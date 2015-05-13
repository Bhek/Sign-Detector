// Sign Detector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Utilities.h"

Mat * sampleImages, *testImages;
int numberOfSampleImages, numberOfTestImages;

Mat * loadImages(int size, char * fileLocation, char ** files) {
	Mat * images = new Mat[size];

	for (int i = 0; i < size; i++) {
		string filename(fileLocation);
		filename.append(files[i]);
		images[i] = imread(filename, -1);
		if (images[i].empty())
		{
			cout << "Could not open " << images[i] << endl;
			return false;
		}
	}
	return images;
}

int _tmain(int argc, _TCHAR* argv[]) {
	// Load sample sign images
	char* sampleFileLocation = "Media/RoadSignRecognitionKnownSigns/";	// Location of sample sign images
	char* sampleFiles[] = {	// Sample sign images
		"RoadSignGoLeft.JPG",
		"RoadSignGoRight.JPG",
		"RoadSignGoStraight.JPG",
		"RoadSignNoLeftTurn.JPG",
		"RoadSignNoParking.JPG",
		"RoadSignNoRightTurn.JPG",
		"RoadSignNoStraight.JPG",
		"RoadSignParking.JPG",
		"RoadSignYield.JPG"
	};

	int numberOfSampleImages = sizeof(sampleFiles) / sizeof(sampleFiles[0]);	// Number of sample sign images
	sampleImages = loadImages(numberOfSampleImages, sampleFileLocation, sampleFiles);

	// Load images to be tested
	char* testFileLocation = "Media/RoadSignRecognitionUnknownSigns/";	// Location of testing images
	char* testFiles[] = {	// Test images
		"RoadSigns1.jpg",
		"RoadSigns2.jpg",
		"RoadSigns3.jpg",
		"RoadSignsComposite1.JPG",
		"RoadSignsComposite2.JPG"
	};

	numberOfTestImages = sizeof(testFiles) / sizeof(testFiles[0]);	// Number of images to be tested
	testImages = loadImages(numberOfTestImages, testFileLocation, testFiles);

	for (int i = 0; i < numberOfSampleImages; i++) {
		imshow("Sample Images", sampleImages[i]);
		waitKey(0);
	}

	for (int i = 0; i < numberOfTestImages; i++) {
		imshow("Test Images", testImages[i]);
		waitKey(0);
	}

	return 0;
}