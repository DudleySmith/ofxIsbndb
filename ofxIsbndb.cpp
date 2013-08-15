#include "ofxIsbndb.h"

ofxIsbndb::ofxIsbndb()
{
    //ctor
}

ofxIsbndb::~ofxIsbndb()
{
    //dtor
}

// Send URL to store refs from one isbn number ---------------
string ofxIsbndb::urlRequest_book(double _isbn){

    string urlRequest = urlRequest_basis();

    urlRequest += "/book";
    urlRequest += "/" + ofToString(_isbn, 0, 13, '0');

    return urlRequest;

}

// Return Basis URL needed ---------------
string ofxIsbndb::urlRequest_basis(){

    string urlRequest = "";

    urlRequest += URL_isbndbBasic;
    urlRequest += URL_ForXML;
    urlRequest += "/";
    urlRequest += apiKey_isbndb;

    return urlRequest;

}
