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
        case '(': return OPAREN;
        case ')': return CPAREN;
            
        case '!':
            if(in.get() == '=') return NOTEQUAL;
            else return NOT;
        
        case '~': return BIT_COMP;
            
        case '-': return MINUS;
        case '+': return PLUS;
            
        case '*': return MULT;
        case '/': return DIV;
        case '%': return MODULUS;
            
        case '<':
            if(in.get() == '<') return SHIFT_L;
            else if(in.get() == '=') return LE;
            else return LT;
            
        case '>':
            if(in.get() == '>') return SHIFT_R;
            else if(in.get() == '=') return GE;
            else return LT;
        
        case '=': return EQUAL; //Shouldn't be used except to determine greater/less equal
            
        case '&':
            if(in.get() == '&') return LOG_AND;
            else return BIT_AND;
            
        case '^': return BIT_EOR;
        case '|':
            if(in.get() == '|') return LOG_OR;
            else return BIT_IOR;

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
