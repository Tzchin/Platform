#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	Vec co;
	co.x = 0;
	co.y = ofGetHeight() - 100;
	walls.push_back(new StaticRect(co, 1000, 100));
	Vec pCo;
	pCo.x = ofGetWidth() / 2;
	pCo.y = ofGetHeight() / 2;
	objs.push_back(new Player(pCo, 20, 20, 5));
	
}

//--------------------------------------------------------------
void ofApp::update(){

	for (int i = 0; i < objs.size(); i++) //Updates all moving objects positions
	{
		objs[i]->updatePos(walls);
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofPushMatrix();
	ofPushStyle();
	ofSetColor(255, 162, 56);
	for (int i = 0; i < walls.size(); i++) //Draws all walls
	{
		
		ofDrawRectangle(walls[i]->getTL().x, walls[i]->getTL().y, walls[i]->getWidth(), walls[i]->getHeight());
	}
	ofPopStyle();
	ofPopMatrix();
	
	//Draws movable objects
	ofPushMatrix();
	ofPushStyle();
	ofSetColor(255, 56, 56);
	for (int i = 0; i < objs.size(); i++)
	{

		ofDrawRectangle(objs[i]->getTL().x, objs[i]->getTL().y, objs[i]->getWidth(), objs[i]->getHeight());
	}
	ofPopStyle();
	ofPopMatrix();

	ofPushStyle();
	ofSetColor(255, 255, 255);
	ofDrawBitmapString(objs[0]->getPos().x, 10, 20);
	ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	if (key == 'a')
	{
		objs[0]->moveLeft();
	}
	if (key == 'd')
	{
		objs[0]->moveRight();
	}
	if (key == 'w')
	{
		objs[0]->jump();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == 'a')
	{
		objs[0]->stopLeft();
	}
	if (key == 'd')
	{
		objs[0]->stopRight();
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	//stores mouse pos
	mouseCo.x = x;
	mouseCo.y = y;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

	Vec co;
	co.x = x;
	co.y = y;
	walls.push_back(new StaticRect(mouseCo, co));
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

/*vector<StaticRect*> ofApp::getWalls()
{
	return walls;
}*/

bool ofApp::checkCollision(MovableBody * obj, StaticRect * wall)
{
	//Note only works for rectangle collision for now

	return ((obj->getTL().x <= wall->getBR().x && obj->getBR().x >= wall->getTL().x) //Checks x-axis alignment
		&& (obj->getTL().y <= wall->getBR().y && obj->getBR().y >= wall->getTL().y)); //Checks y-axis alignment
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
