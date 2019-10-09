



Mat canny_output;
vector<vector<Point> > contours;
vector<Vec4i> hierarchy;

// detect edges using canny
Canny( gray, canny_output, 50, 150, 3 );

// find contours
findContours( canny_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0) );

// get the moments
vector<Moments> mu(contours.size());
for( int i = 0; i<contours.size(); i++ )
{ mu[i] = moments( contours[i], false ); }

// get the centroid of figures.
vector<Point2f> mc(contours.size());
for( int i = 0; i<contours.size(); i++)
{ mc[i] = Point2f( mu[i].m10/mu[i].m00 , mu[i].m01/mu[i].m00 ); }


// draw contours
Mat drawing(canny_output.size(), CV_8UC3, Scalar(255,255,255));
for( int i = 0; i<contours.size(); i++ )
{
Scalar color = Scalar(167,151,0); // B G R values
drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
circle( drawing, mc[i], 4, color, -1, 8, 0 );
}

// show the resultant image
namedWindow( "Contours", WINDOW_AUTOSIZE );
imshow( "Contours", drawing );
waitKey(0);