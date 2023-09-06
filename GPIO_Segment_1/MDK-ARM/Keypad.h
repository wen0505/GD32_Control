#define 	KB_R_Blank 		GPIOC->ODR|=(0x000f)				//Blank Row
#define 	KB_R_Scan(x) 	GPIOC->ODR&=~(1<<x)					//R1~R4 Output Low

#define   KB_C1 				!((GPIOB->IDR & (1<<0))>>0)	  //C1=0?
#define   KB_C2 				!((GPIOB->IDR & (1<<1))>>1)	  //C2=0?
#define   KB_C3 				!((GPIOB->IDR & (1<<2))>>2)	  //C3=0?
#define   KB_C4 				!((GPIOB->IDR & (1<<3))>>3)	  //C4=0?
