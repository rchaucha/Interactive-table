#include "TrackingTools.hpp"

#include "tools/detection/DetectionTools.hpp"


// Permet de traquer les objets en fonction des filtres de couleurs HSV via sliders
int TrackingTools::traitementCouleur(VideoCapture video)
{
   if (!video.isOpened())
   {
      cout << "Could not read video file" << endl;
      return 1;
   }

   namedWindow("Control"); //create a window called "Control"

   int iLowH = 0, iHighH = 179, iLowS = 130, iHighS = 255, iLowV = 0, iHighV = 255;

   //Create trackbars in "Control" window
   createTrackbar("LowH", "Control", &iLowH, 179);    // Hue
   createTrackbar("HighH", "Control", &iHighH, 179);
   createTrackbar("LowS", "Control", &iLowS, 255);    // Saturation
   createTrackbar("HighS", "Control", &iHighS, 255);
   createTrackbar("LowV", "Control", &iLowV, 255);    // Value
   createTrackbar("HighV", "Control", &iHighV, 255);

   int iLastX = -1, iLastY = -1;

   // Image temporaire juste pour connaitre la taille de l'image de la webcam
   Mat imgTmp;
   video.read(imgTmp);

   //Create a black image with the size as the camera output
   Mat imgLines = Mat::zeros(imgTmp.size(), CV_8UC3);;

   while (true)
   {
      Mat imgOriginal;

      bool bSuccess = video.read(imgOriginal); // read a new frame from video

      if (!bSuccess)
      {
         cout << "Cannot read a frame from video stream" << endl;
         break;
      }

      Mat imgHSV;
      Mat imgThresholded;

      cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV

      inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image

      //morphological opening (removes small objects from the foreground)
      erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
      dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

      //Calculate the moments of the thresholded image
      Moments oMoments = moments(imgThresholded);

      double dM01 = oMoments.m01;
      double dM10 = oMoments.m10;
      double dArea = oMoments.m00;

      // if the area <= 10000, I consider that the there are no object in the image 
      if (dArea > 10000)
      {
         //calculate the position of the ball
         int posX = dM10 / dArea;
         int posY = dM01 / dArea;

         if (iLastX >= 0 && iLastY >= 0 && posX >= 0 && posY >= 0)
            line(imgLines, Point(posX, posY), Point(iLastX, iLastY), Scalar(0, 0, 255), 2);

         iLastX = posX;
         iLastY = posY;
      }

      imshow("Thresholded Image", imgThresholded); //show the thresholded image

      imgOriginal = imgOriginal + imgLines;
      imshow("Original", imgOriginal); //show the original image

      if (waitKey(1) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
      {
         cout << "esc key is pressed by user" << endl;
         break;
      }
   }
   return 0;
}


// Permet de traquer les objets à partir de rectangles dessinés au début
void TrackingTools::glassesTracking(VideoCapture video)
{
   auto initTrackers = [](VideoCapture& video, vector<Rect2d>& bboxes, Ptr<MultiTracker>& multiTracker)
   {
      Mat frame;
      do { // get bounding box
         video >> frame;
         bboxes = DetectionTools::glasses(frame);
      } while (bboxes.size() < 1);

      multiTracker = cv::MultiTracker::create();

      for (int i = 0; i < bboxes.size(); i++)
         multiTracker->add(TrackerGlass::create(), frame, Rect2d(bboxes[i]));
   };

   Mat frame;
   vector<Rect2d> bboxes;
   Ptr<MultiTracker> multiTracker;

   for (int i = 0; i < 30; i++) { video >> frame; }      // on laisse passer quelques images pour que la camera se stablilise

   initTrackers(video, bboxes, multiTracker);

   while (true)
   {
      video >> frame;

      if (frame.rows == 0 || frame.cols == 0)  // stop the program if no more images
         break;

      multiTracker->update(frame);

      for (unsigned i = 0; i < multiTracker->getObjects().size(); i++)
         rectangle(frame, multiTracker->getObjects()[i], Scalar(255, 0, 0), 2, 1);

      imshow("MultiTracker", frame);  // show image with the tracked object

      int key = waitKey(1);
      if (key == 27)       // quit on ESC button 
         break;
      else if (key == 32)  // on re-détecte les verres lorsque Espace est pressé
      {
         cout << "Reinitialisation des trackers" << endl;
         initTrackers(video, bboxes, multiTracker);
      }
   }
}
