#define BUFFER 2


typedef struct {
	char *s;
	size_t len;
	size_t b_size;
} str;


str * str_init();
void str_append(str *s, char c);
void str_resize(str *old, int buff);

/**
	Initialize the string object
*/
str * str_init() {
	str *new_str = (str *) malloc(sizeof(str));
	
	new_str->s = (char *) malloc(sizeof(char)*BUFFER);
	if (new_str->s == NULL){
		nomem_error(__file__, __func__, __line__);		
	}
	
	//init the other properties
	new_str->len = 0;
	new_str->b_size = BUFFER;
	
	return new_str;
}

void str_resize(str *old, int buff) {
	/*
		base method to resize string when it gets out of bounds
	*/
	char *tmp = (char *) malloc(sizeof(char)*(buff));
	
	if (tmp == NULL){
		nomem_error(__file__, __func__, __line__);
	}
	
	// copy and free old string
	strcpy(tmp, old->s);
	free(old->s);
	
	//re-point pointer
	old->s = tmp;
	old->b_size = buff;

}

void str_append(str *s, char c) {
	
	if(s->len+1 >= s->b_size) { /* check for out-of-bounds + null char */
		/* string is out of bounds */
		str_resize(s, (s->b_size + BUFFER));	
	}
	
	s->s[s->len++] = c;
	s->s[s->len] = '\0'; 
		
}