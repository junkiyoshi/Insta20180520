#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(39, 39, 239);
	ofSetWindowTitle("Insta");

	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}


//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	int rect_len = 120;
	for (int x = -ofGetWidth() / 2 + rect_len / 2; x <= ofGetWidth() / 2 - rect_len / 2; x += rect_len) {

		for (int y = -ofGetHeight() / 2 + rect_len / 2; y <= ofGetHeight() / 2 - rect_len / 2; y += rect_len) {

			this->draw_rect_and_circle(ofPoint(x, y), rect_len);
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
void ofApp::draw_rect_and_circle(ofPoint point, int rect_len) {

	ofPushMatrix();
	ofTranslate(point);

	int radius = rect_len * 0.45;

	ofBeginShape();
	ofVertex(-rect_len / 2, -rect_len / 2);
	ofVertex(rect_len / 2, -rect_len / 2);
	ofVertex(rect_len / 2, rect_len / 2);
	ofVertex(-rect_len / 2, rect_len / 2);

	ofNextContour();
	for (int deg = 0; deg < 360; deg += 1) {

		ofVertex(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
	}
	ofEndShape(true);

	radius *= ofMap(ofNoise(point.x * 0.001, point.y * 0.001, ofGetFrameNum() * 0.01), 0, 1, 0.4, 1.2);
	ofBeginShape();
	for (int deg = 0; deg < 360; deg += 1) {

		ofVertex(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
	}
	ofEndShape(true);

	ofPopMatrix();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}