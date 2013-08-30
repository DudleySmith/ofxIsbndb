
// API ---------------------------------------------

// Key generated with account on isbndb
#define apiKey_isbndb  "T5W9O9Q9"
// Responses
#define apiStatus_Found 200
#define apiRequest_Name_Book "book"

// URLs -----------------------------------------
#define URL_isbndbBasic     "http://isbndb.com"

#define URL_ForJson        "/api/v2/json"
#define URL_ForYaml        "/api/v2/yaml"
#define URL_ForXML         "/api/v2/xml"

#define URL_slash        "/"

#define URL_request_book            "/book"
#define URL_request_books           "/books"
#define URL_request_author          "/author"
#define URL_request_authors         "/authors"
#define URL_request_publisher       "/publisher"
#define URL_request_publishers      "/publishers"
#define URL_request_subject         "/subject"
#define URL_request_subjects        "/subjects"
#define URL_request_category        "/category"
#define URL_request_categories      "/categories"
#define URL_request_prices          "/prices"

/*
TAGS for content in Xml
http://isbndb.com/api/v1/docs/books

*/
#define ISBN_API_TAG_header                 "isbndb"
#define ISBN_API_TAG_data                   "data"

#define ISBN_API_TAG_author_data            "author_data"
#define ISBN_API_TAG_author_data_id         "author_data:id"
#define ISBN_API_TAG_author_data_name       "author_data:name"
        
#define ISBN_API_TAG_urls_text              "urls_text"
#define ISBN_API_TAG_title_long             "title_long"
#define ISBN_API_TAG_title_latin            "title_latin"
#define ISBN_API_TAG_summary                "summary"

#define ISBN_API_TAG_title                          "title"
#define ISBN_API_TAG_publisher_text                 "publisher_text"
#define ISBN_API_TAG_publisher_name                 "publisher_name"
#define ISBN_API_TAG_publisher_id                   "publisher_id"
#define ISBN_API_TAG_physical_description_text      "physical_description_text"
#define ISBN_API_TAG_notes                          "notes"
#define ISBN_API_TAG_marc_enc_level                 "marc_enc_level"
#define ISBN_API_TAG_lcc_number                     "lcc_number"
#define ISBN_API_TAG_language                       "language"
#define ISBN_API_TAG_isbn13                         "isbn13"
#define ISBN_API_TAG_isbn10                         "isbn10"
#define ISBN_API_TAG_edition_info                   "edition_info"
#define ISBN_API_TAG_dewey_normal                   "dewey_normal"
#define ISBN_API_TAG_dewey_decimal                  "dewey_decimal"
#define ISBN_API_TAG_book_id                        "book_id"
