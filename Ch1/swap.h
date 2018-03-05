template<typename Obj>

	void swap (Obj *a,Obj *b){

		Obj * t = a;
		*a = *b;
		*b = *t;
		//~t;
	}