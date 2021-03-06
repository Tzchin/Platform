#pragma once

#include "ofMain.h"
#include "StaticRect.h"
#include "StaticTriangle.h"
#include "Vec.h"
#include "MovableBody.h"
#include "Player.h"
#include <string>
#include <vector>

//class MovableBody;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
//		vector <StaticRect *> getWalls();
		
	private:
		vector <StaticBody *> walls;
		vector <MovableBody *> objs;
		Vec mouseCo;
		bool checkCollision(MovableBody * obj, StaticRect * wall);
        Vec screenOffset;
        Player * player;
};
