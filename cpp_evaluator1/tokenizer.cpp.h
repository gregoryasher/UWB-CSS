template <class NumericType>
bool Tokenizer<NumericType>::getChar( char &ch ) {
  char tmp;

  // skip blanks
  while ( in.get( tmp ) && tmp == ' ' );

  // read a char 
  if ( in.good( ) && tmp != '\n'&& tmp != '\0' ) {
    ch = tmp;
    return true; // if it is not a delimiter
  }
  else
    return false; // if it's a delimitter
}

template <class NumericType>
Token<NumericType> Tokenizer<NumericType>::getToken( ) {

  char ch;
  NumericType theValue;

  if ( getChar( ch ) == true ) {
    switch( ch ) {
    case '/': return DIV;
    case '*': return MULT;
    case '(': return OPAREN;
    case ')': return CPAREN;
    case '+': return PLUS;
    case '-': return MINUS;
    default:
      in.putback( ch );
      if ( !( in >> theValue ) ) {
	cerr << "Parse error" << endl;
	return EOL;
      }
      return Token<NumericType>( VALUE, theValue );
    }
  }

  return EOL;
}
