#pragma once
#include <sqlite3.h>
#include "Card.hpp"
#include "searchrequest.h"


std::vector<Card> searchFor(SearchRequest);
std::vector<Card> getCards(std::string);
Card turnIntoCard(sqlite3_stmt*);
void takePluralData(Card&, sqlite3*);
std::string prepareSQLQuery(SearchRequest);