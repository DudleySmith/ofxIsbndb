// ----------------------------------------------------
//
// 2013/08/11 : Buis-les-baronnies (France) : created by Vj Dudley Smith (vj.dudley.smith@gmail.com). My first addon; be kind with him.
//
// ofxIsbndb : Addon built to connect to isbdn.org and retreive standard library datas
//
// ----------------------------------------------------
#pragma once

#include "ofMain.h"
#include "ofxIsbndb_define.h"

class ofxIsbndb
{
    public:
        ofxIsbndb();
        virtual ~ofxIsbndb();

        string urlRequest_book(double _isbn);

    protected:
    private:
        string urlRequest_basis();

};

