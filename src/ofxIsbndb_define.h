
// API ---------------------------------------------

// Key generated with account on isbndb
#define apiKey_isbndb  "T5W9O9Q9"
// Responses
#define apiStatus_Found 200
#define apiStatus_dontKnow 302
#define apiRequest_Name_Book "book"

// URLs -----------------------------------------
#define URL_isbndbBasic     "http://isbndb.com/api"

#define URL_ForJson        ".json"
#define URL_ForYaml        ".yaml"
#define URL_ForXML         ".xml"

#define URL_slash        "/"

#define URL_request_accessKey          "access_key"

#define URL_request_index1          "index1"
#define URL_request_index1_isbn     "isbn"

#define URL_request_value1          "value1"

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
#define ISBN_API_TAG_header                 "ISBNdb"
#define ISBN_API_TAG_BookList               "BookList"
#define ISBN_API_TAG_BookList_ATT_total_results           "total_results"
#define ISBN_API_TAG_BookList_ATT_page_size               "page_size"
#define ISBN_API_TAG_BookList_ATT_page_number             "page_number"
#define ISBN_API_TAG_BookList_ATT_shown_results           "shown_results"

// Example        <BookData book_id="les_cantos_dhyperion_tome_1" isbn="2266111566" isbn13="9782266111560">
#define ISBN_API_TAG_BookData               "BookData"
#define ISBN_API_TAG_BookData_ATT_book_id            "book_id"
#define ISBN_API_TAG_BookData_ATT_isbn               "isbn"
#define ISBN_API_TAG_BookData_ATT_isbn13             "isbn13"


#define ISBN_API_TAG_AuthorsText            "AuthorsText"
#define ISBN_API_TAG_Title                   "Title"


// Those following are not tested with the API V2 !!!
#define ISBN_API_TAG_author_data            "author_data"
#define ISBN_API_TAG_author_data_id         "author_data:id"
#define ISBN_API_TAG_author_data_name       "author_data:name"

#define ISBN_API_TAG_urls_text              "urls_text"
#define ISBN_API_TAG_title_long             "title_long"
#define ISBN_API_TAG_title_latin            "title_latin"
#define ISBN_API_TAG_summary                "summary"


#define ISBN_API_TAG_publisher_text                 "publisher_text"
#define ISBN_API_TAG_publisher_name                 "publisher_name"
#define ISBN_API_TAG_publisher_id                   "publisher_id"
#define ISBN_API_TAG_physical_description_text      "physical_description_text"
#define ISBN_API_TAG_notes                          "notes"
#define ISBN_API_TAG_marc_enc_level                 "marc_enc_level"
#define ISBN_API_TAG_lcc_number                     "lcc_number"
#define ISBN_API_TAG_language                       "language"

#define ISBN_API_TAG_edition_info                   "edition_info"
#define ISBN_API_TAG_dewey_normal                   "dewey_normal"
#define ISBN_API_TAG_dewey_decimal                  "dewey_decimal"
#define ISBN_API_TAG_book_id                        "book_id"
