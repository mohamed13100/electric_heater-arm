

#include "main.h"



#include "SSD_Interface.h"
#include "SSD_Config.h"
#include "SSD_Privat.h"

/**********************************************************************/
/**********************************************************************/

volatile uint16_t arr[]={ 0xff3f ,0xff06 ,0xff5b ,0xff4f ,0xff66 ,0xff6d ,0xff7d ,0xff47 ,0xff7f ,0xff6f ,0xff77 ,0xff3f ,0xff71 ,0xff40};




void SSD_voidDisplay(uint8_t Copy_u8Number)
{

	switch(Copy_u8Number)
	{
	case 0 : //DATA
				HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_RESET);
 	break;

	case 1 :
				HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_RESET);
	break;

	case 2 :
				HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_SET);
	break;

	case 3 :
				HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_SET);
	break;

	case 4 :
				HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_SET);



	break;

	case 5 :
				HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_SET);

		break;

	case 6 :

				HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_SET);
		break;

	case 7 :
				HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_RESET);

		break;

	case 8 :
				HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_SET);

		break;

	case 9 :
		 	 	HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_SET);

		break;

	case 10 :
			 	 	HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_SET);

			break;

	case 11 :
			 	 	HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_RESET);

			break;

	}
}

/**********************************************************************/
/**********************************************************************/






