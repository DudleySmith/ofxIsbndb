#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    // We have to define the object for callback
    ofRegisterURLNotification(&m_oIsbndb);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    string message = "";
    
    // We announce what we do
    message += "Example ofxIsbndb : Access to isbndb API.\n\n";
    message += "a/A : Ask a number and send to isbndb\n";
    message += "z/Z : Send to isbndb the number of :  Les Cantos d'Hyperion\n";
    message += "e/E : Send to isbndb the number of :  Slumdog millionar (this is times out ! )\n\n";
    message += "All of them are french books, bien sžr";
    
    ofDrawBitmapString(message, 50, 50);
    
    // Display result
    ofDrawBitmapString(m_oIsbndb.get_BookReceived().toString(), 50, 250);
    
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
    string isbnTyped;
    
    switch(key){
            
        case 'a':
        case 'A':
            // Ask the number on the back of a book and send it
            isbnTyped = ofSystemTextBoxDialog("Type the number on the back of your book");
            m_oIsbndb.send(isbnTyped);
            break;
        case 'z':
        case 'Z':
            // Send Hyperion ISBN Code : it works !
            m_oIsbndb.send(ofToString(ISBN13_HyperionTome1));
            break;
            
        case 'e':
        case 'E':
            // Send Hyperion ISBN Code : it does not work and go to time out !
            m_oIsbndb.send(ofToString(ISBN13_SlumDog));
            break;
            
        default:
            break;
            
    }
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}