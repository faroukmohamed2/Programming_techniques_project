#include "GUI\Input.h"
#include "GUI\Output.h"
#include <cmath>
//This is a test code to test the Input and Output classes

int main()
{
	int x,y;

	//Create Input and Output objects to test
	Output *pOut = new Output();
	Input *pIn = pOut->CreateInput();

	//Starting the test
	pOut->PrintMessage("This demo is to test input and output classes, Click anywhere to start the test");
	pIn->GetPointClicked(x,y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 1:	
	//			Create The FULL Tool bar, the drawing area and the status bar	
	//			This has already been done through the constrcutor of class Output
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST1: Drawing Tool bar and Status bar, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	
	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:	
	//			Drawing all the Figures with all possible states: 
	//			Non-filled, Filled, and highlighted in both cases			
	///////////////////////////////////////////////////////////////////////////////////
	
	pOut->PrintMessage("TEST2: Now we will show that Output class can draw any figure in any state, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	GfxInfo gfxInfo;//to be used with draw function of the class Ouput
	Point P1, P2, P3;

	/// 2.1- Rectangle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Rectangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	// 2.1.1 - Drawing non-filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> non-filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->getValidDrawPoint(P1);// this function is used to check that we don't draw over the status or tool bar
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->getValidDrawPoint(P2);

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawRect(P1, P2, gfxInfo, false);
	pOut->PrintMessage("Drawing a Rectangle ==>non-filled ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	// 2.1.2 - Drawing highlighted non-filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawRect(P1, P2, gfxInfo, true);
	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted non-filled ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	// 2.1.3 - Drawing a filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->getValidDrawPoint(P1);
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->getValidDrawPoint(P2);

	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;	//any color for border
	gfxInfo.FillClr = GREEN;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->DrawRect(P1, P2, gfxInfo, false);
	pOut->PrintMessage("Drawing a Rectangle ==> filled ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click


	// 2.1.4 - Drawing a highlighted filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawRect(P1, P2, gfxInfo, true);



	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted filled ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.2- Square Test ///
	/// ============== 

	
	pOut->PrintMessage("Drawing a Square, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	// 2.2.1 - Drawing non-filled Square
	pOut->PrintMessage("Drawing a Square ==> non-filled,  Click one point");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->getValidDrawPoint(P1);

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = GREEN;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawSquare(P1, gfxInfo, false);
	pOut->PrintMessage("Drawing Square==>non-filled ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	// 2.2.2 - Drawing highlighted non-filled Square
	pOut->PrintMessage("Drawing a Square ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawSquare(P1, gfxInfo, true);
	pOut->PrintMessage("Drawing a Square==> Highlighted non-filled ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	// 2.2.3 - Drawing a filled Square
	pOut->PrintMessage("Drawing a Square ==> filled,  Click one point");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->getValidDrawPoint(P1);
	

	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = GREEN;	//any color for border
	gfxInfo.FillClr = BLUE;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->DrawSquare(P1, gfxInfo, false);
	pOut->PrintMessage("Drawing a Square ==> filled ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click


	// 2.2.4 - Drawing a highlighted filled Square
	pOut->PrintMessage("Drawing a Square ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawSquare(P1, gfxInfo, true);



	pOut->PrintMessage("Drawing a Square ==> Highlighted filled ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.4- Hexagon Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Hexagon, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	///TODO: Add code to draw Hexagon in all possible states

	// 2.4.1 - Drawing a non filled Hexagon
	pOut->PrintMessage("Drawing a Hexagon ==> non filled,  Click one click");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->getValidDrawPoint(P1);

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = GREEN;
	gfxInfo.isFilled = false;
	pOut->DrawHexa(P1, gfxInfo, false);
	pOut->PrintMessage("Drawing a Hexagon ==> non filled==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click


	// 2.4.2 - Drawing a non-filled and highlighted Hexagon
	pOut->PrintMessage("Drawing a Hexagon ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawHexa(P1, gfxInfo, true);
	pOut->PrintMessage("Drawing a Hexagon ==> Highlighted non-filled ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	// 2.4.3 - Drawing a filled Hexagon
	pOut->PrintMessage("Drawing a Hexagon ==> filled,  Click one click");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->getValidDrawPoint(P1);

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;
	gfxInfo.FillClr = GREEN;
	gfxInfo.isFilled = true;
	pOut->DrawHexa(P1, gfxInfo, false);
	pOut->PrintMessage("Drawing a Hexagon ==> filled==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	// 2.4.4 - Drawing a non-filled and highlighted triangle
	pOut->PrintMessage("Drawing a Hexagon ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawHexa(P1, gfxInfo, true);
	pOut->PrintMessage("Drawing a Hexagon ==> Highlighted filled ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();



	/// 2.5- Circle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing an Circle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	///TODO: Add code to draw Circle in all possible states

	// 2.5.1 - Drawing a non filled Circle
	pOut->PrintMessage("Drawing a Circle ==> non-filled ,  Click two clicks");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->getValidDrawPoint(P1);
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->getValidDrawPoint(P2);

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = GREEN;
	gfxInfo.isFilled = false;
	pOut->DrawCircle(P1, P2, gfxInfo, false);
	pOut->PrintMessage("Drawing a Circle==> non filled==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click


	// 2.5.2 - Drawing a non-filled and highlighted Circle
	pOut->PrintMessage("Drawing a circle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawCircle(P1, P2, gfxInfo, true);
	pOut->PrintMessage("Drawing a circle ==> Highlighted non-filled ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	// 2.5.3 - Drawing a filled Circle
	pOut->PrintMessage("Drawing a Circle ==> filled ,  Click two clicks");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->getValidDrawPoint(P1);
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->getValidDrawPoint(P2);

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;
	gfxInfo.FillClr = GREEN;
	gfxInfo.isFilled = true;
	pOut->DrawCircle(P1, P2, gfxInfo, false);
	pOut->PrintMessage("Drawing a Hexagon ==> filled==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click



	// 2.5.4 - Drawing a filled and highlighted Circle
	pOut->PrintMessage("Drawing a circle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	
	pOut->DrawCircle(P1, P2, gfxInfo, true);
	pOut->PrintMessage("Drawing a circle ==> Highlighted ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);
	pOut->ClearDrawArea();


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3: 
	//			Input Class: Read strings from the user
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST3: Now Time to test class Input, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	
	pOut->PrintMessage("Testing Input ability to read strings");
	string outputmessage = pIn->GetSrting(pOut);
	if (outputmessage != "")
	{
		pOut->ClearStatusBar();
		pOut->PrintMessage("You Entered: " + outputmessage);
		//pOut->PrintMessage(out);
	}
	///TODO: Add code here to 
	// 1- Read a string from the user on the status bar
	// 2- After reading the string clear the status bar
	// 3- print on the status bar "You Entered" then print the string
	pIn->GetPointClicked(x, y);	//Wait for any click*/
	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4: 
	//			Input Class : Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	
	pOut->PrintMessage("TEST4: Testing Input ability to detect User Action, click anywhere");

	ActionType ActType;
	
	///TODO:  
	//You must add a case for each action (both Draw mode and Play mode actions)
	//Add cases for the missing actions below
	do
	{
		ActType = pIn->GetUserAction();

		switch (ActType)
		{
		case DRW_RECT:
			pOut->PrintMessage("Action: Draw a Rectangle , Click anywhere");
			break;
		case DRW_Circ:
			pOut->PrintMessage("Action: Draw a Cirlce , Click anywhere");
			break;
		case DRW_Square:
			pOut->PrintMessage("Action: Draw a Square , Click anywhere");
			break;
		case DRW_Hexa:
			pOut->PrintMessage("Action: Draw a Hexagon , Click anywhere");
			break;
		case DRW_Trig:
			pOut->PrintMessage("Action: Draw a Triangle , Click anywhere");
			break;

		case DRW_Red:
			pOut->PrintMessage("Action: Selected Red Color , Click anywhere");
			break;
		case DRW_Orange:
			pOut->PrintMessage("Action: Selected Orange Color , Click anywhere");
			break;
		case DRW_Blue:
			pOut->PrintMessage("Action: Selected Blue Color , Click anywhere");
			break;
		case DRW_Yellow:
			pOut->PrintMessage("Action: Selected Yellow Color , Click anywhere");
			break;
		case DRW_Green:
			pOut->PrintMessage("Action: Selected Green Color , Click anywhere");
			break;
		case DRW_Black:
			pOut->PrintMessage("Action: Selected Black Color , Click anywhere");
			break;

		case Pencile_Tool:
			pOut->PrintMessage("Action: Selected Pencile , Click anywhere");
			break;
		case Move_Tool:
			pOut->PrintMessage("Action: Move shape , Click anywhere");
			break;

		case Fill_Tool:
			pOut->PrintMessage("Action: selected fill bucket , Click any shape");
			break;
		case Selection_Tool:
			pOut->PrintMessage("Action: selected selection toolxz , Click any shape");
			break;

		case UNDO:
			pOut->PrintMessage("Action: Undid [LAST ACTION]");
			break;

		case REDO:
			pOut->PrintMessage("Action: Redid [LAST ACTION]");
			break;

		case Delete:
			pOut->PrintMessage("Action: selected deletion tool , Click any shape");
			break;

		case ClearBoard:
			pOut->PrintMessage("Action: Cleared board");
			break;
		case START_RECORD:
			pOut->PrintMessage("Action: Recording Started.");
			break;
		case STOP_RECORD:
			pOut->PrintMessage("Action: Recording stoped.");
			break;
		case SAVE_RECORD:
			pOut->PrintMessage("Action: Recording saved.");
			break;
		case PLAY_RECORD:
			pOut->PrintMessage("Action: Playing the record.");
			break;
		case LOAD_RECORD:
			pOut->PrintMessage("Action: Recording loaded.");
			break;

		case STATUS:
			pOut->PrintMessage("Action: a click on the Status Bar, Click anywhere");
			break;

		case DRAWING_AREA:
			pOut->PrintMessage("Action: a click on the Drawing Area, Click anywhere");
			break;
		case EMPTY:
			pOut->PrintMessage("Action: a click on empty area in the Design Tool Bar, Click anywhere");
			break;

		case TO_DRAW:
			pOut->PrintMessage("Action: Switch to Draw Mode, creating simualtion tool bar");
			pOut->CreateDrawToolBar();
			break;

		case TO_PLAY:
			pOut->PrintMessage("Action: Switch to Play Mode, creating Design tool bar");
			pOut->CreatePlayToolBar();
			break;
		case FIG_TYP:
			pOut->PrintMessage("Action: Select the shape");
			break;
		case FIG_COL:
			pOut->PrintMessage("Action: Select by the color");
			break;
		case FIG_TYP_COL:
			pOut->PrintMessage("Action: Select the shape of color");
			break;
		case RESET:
			pOut->PrintMessage("Action: Restart the game");
			break;


			///TODO: Add more cases for the other action types


		case EXIT:
			break;
		}
	}while(ActType != EXIT);


	/// Exiting
	pOut->PrintMessage("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(x,y);


	delete pIn;
	delete pOut;	
	return 0;
}


