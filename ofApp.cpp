#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	Vec co;
	co.x = 0;
	co.y = ofGetHeight() - 100;
	walls.push_back(new StaticRect(co, 1000, 100));
	ofPoint co2;
	co2.x = 0;
	co2.y = ofGetHeight() - 150;
	walls.push_back(new StaticTriangle(co2, 100, -100));
	Vec pCo;
	pCo.x = ofGetWidth() / 2;
	pCo.y = ofGetHeight() / 2;
	objs.push_back(new Player(pCo, 20, 20, 5));
    screenOffset.x = 0;
    screenOffset.y = 0;
    player = (Player*)objs[0];
	
}

//--------------------------------------------------------------
void ofApp::update(){

	for (int i = 0; i < objs.size(); i++) //Updates all moving objects positions
	{
		objs[i]->updatePos(walls);
	}
    
    screenOffset.x = ofGetWidth()/2 - player->getPos().x;
    if(player->getPos().y > ofGetHeight()/2)
    {
        screenOffset.y = 0;
    }
    else
    {
        screenOffset.y = ofGetHeight()/2 - player->getPos().y;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
	
    ofPushMatrix();
    ofTranslate(screenOffset.x, screenOffset.y);
    
	ofPushMatrix();
	ofPushStyle();
	ofSetColor(255, 162, 56);
	for (int i = 0; i < walls.size(); i++) //Draws all walls
	{
		walls[i]->draw();
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

    
    ofPopMatrix();
    
    ofPushStyle();
    ofSetColor(255, 255, 255);
    ofDrawBitmapString(player->getPos().x, 10, 20);
     ofDrawBitmapString(player->getPos().y, 10, 40);
    ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	if (key == 'a')
	{
		player->moveLeft();
	}
	if (key == 'd')
	{
		player->moveRight();
	}
	if (key == 'w')
	{
		player->jump();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == 'a')
	{
		player->stopLeft();
	}
	if (key == 'd')
	{
		player->stopRight();
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
	mouseCo.x = x - screenOffset.x;
	mouseCo.y = y - screenOffset.y;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

	Vec co;
	co.x = x - screenOffset.x;
	co.y = y - screenOffset.y;

	if(button == 0)
		walls.push_back(new StaticRect(mouseCo, co));
	else if (button == 2)
	{
		ofPoint pt;
		pt.y = mouseCo.y;
		pt.x = co.x;
		int width = mouseCo.x - co.x;
		int height = co.y - mouseCo.y;
		walls.push_back(new StaticTriangle(pt, width, height));
	}
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
