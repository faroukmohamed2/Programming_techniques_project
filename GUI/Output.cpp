#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 60;
	UI.MenuItemWidth = 60;
	UI.MenuItemHeight = 30;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	//CreateDrawToolBar();
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;
	pWind->SetPen( WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight, FILLED);
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImagesGR[DRAW_ITM_COUNT];
	MenuItemImagesGR[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImagesGR[ITM_Circ] = "images\\MenuItems\\Menu_Circ.jpg";
	MenuItemImagesGR[ITM_Square] = "images\\MenuItems\\Menu_Square.jpg";
	MenuItemImagesGR[ITM_Hexa] = "images\\MenuItems\\Menu_Hexa.jpg";
	MenuItemImagesGR[ITM_Trig] = "images\\MenuItems\\Menu_Trig.jpg";

	MenuItemImagesGR[ITM_Red] = "images\\MenuItems\\Menu_Red.jpg";
	MenuItemImagesGR[ITM_Orange] = "images\\MenuItems\\Menu_Orange.jpg";
	MenuItemImagesGR[ITM_Blue] = "images\\MenuItems\\Menu_Blue.jpg";
	MenuItemImagesGR[ITM_Yellow] = "images\\MenuItems\\Menu_Yellow.jpg";
	MenuItemImagesGR[ITM_Green] = "images\\MenuItems\\Menu_Green.jpg";
	MenuItemImagesGR[ITM_Black] = "images\\MenuItems\\Menu_Black.jpg";

	MenuItemImagesGR[ITM_Border] = "images\\MenuItems\\Menu_Border.jpg";
	MenuItemImagesGR[ITM_Move] = "images\\MenuItems\\Menu_Move.jpg";
	MenuItemImagesGR[ITM_Fill] = "images\\MenuItems\\Menu_Fill.jpg";
	MenuItemImagesGR[ITM_Undo] = "images\\MenuItems\\Menu_Undo.jpg";
	MenuItemImagesGR[ITM_Delete] = "images\\MenuItems\\Menu_Del.jpg";
	MenuItemImagesGR[ITM_Redo] = "images\\MenuItems\\Menu_Redo.jpg";
	MenuItemImagesGR[ITM_ClearALL] = "images\\MenuItems\\Menu_Clear.jpg";
	MenuItemImagesGR[ITM_Start] = "images\\MenuItems\\Menu_Start.jpg";
	MenuItemImagesGR[ITM_Select] = "images\\MenuItems\\Menu_Select.jpg";
	MenuItemImagesGR[ITM_Stop] = "images\\MenuItems\\Menu_Stop.jpg";
	MenuItemImagesGR[ITM_Save] = "images\\MenuItems\\Menu_Save.jpg";
	MenuItemImagesGR[ITM_Play] = "images\\MenuItems\\Menu_Play.jpg";
	MenuItemImagesGR[ITM_Load] = "images\\MenuItems\\Menu_Load.jpg";
	
	MenuItemImagesGR[ITM_Game] = "images\\MenuItems\\Menu_Game.jpeg";
	MenuItemImagesGR[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	int Printed = 0; 
	int UpperItems = 0; 
	DrawGROUP(UpperItems,Printed ,NumGR1, MenuItemImagesGR);
	DrawGROUP (UpperItems, Printed , NumGR2, MenuItemImagesGR);
	DrawGROUP(UpperItems, Printed , NumGR3, MenuItemImagesGR);
	DrawGROUP (UpperItems, Printed , NumGR4, MenuItemImagesGR);
	
	pWind->DrawImage(MenuItemImagesGR[Printed++], UI.width - (3 * UI.MenuItemWidth), 0, 1.5 * UI.MenuItemWidth, (UI.ToolBarHeight));
	pWind->DrawImage(MenuItemImagesGR[Printed], UI.width - (1.5 * UI.MenuItemWidth), 0, 1.5 * UI.MenuItemWidth, UI.ToolBarHeight);
	


		//Draw a line under the toolbar
	//pWind->SetPen(RED, 1);
	//pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawGROUP(int& UpperITEMS ,int& Printed , const int ITEMS , const string MenuItemImagesGR[DRAW_ITM_COUNT] ) const  {

	
	int x = 2 * UpperITEMS;

	
	for (int i = Printed; i < ITEMS + Printed; i++) {

		if (x % 2 == 0)
			pWind->DrawImage(MenuItemImagesGR[i], (x++ / 2) * UI.MenuItemWidth, 0, UI.MenuItemWidth, (UI.MenuItemHeight));
		else
			pWind->DrawImage(MenuItemImagesGR[i], (x++ / 2) * UI.MenuItemWidth, UI.ToolBarHeight / 2, UI.MenuItemWidth, (UI.MenuItemHeight));

	}

	UpperITEMS += (ITEMS+1) / 2;
	Printed += ITEMS; 
}



void Output::CreatePlayToolBar() const
{
	/*output_play_mode*/
	UI.InterfaceMode = MODE_PLAY;
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight, FILLED);

	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[FIG_TYPE] = "images\\MenuItems\\fig_type.jpg";
	MenuItemImages[FIG_COLOR] = "images\\MenuItems\\fig_color.jpg";
	MenuItemImages[FIG_TYPE_COLOR] = "images\\MenuItems\\fig_color_type.jpg";
	MenuItemImages[RESTART] = "images\\MenuItems\\restart.jpg";
	MenuItemImages[SWITCH_DRAW] = "images\\MenuItems\\draw_mode.jpg";
	MenuItemImages[ITM_EXIT_PLAY] = "images\\MenuItems\\Menu_Exit.jpg";

	for (int i = 0; i < PLAY_ITM_COUNT - 2; i++)
		pWind->DrawImage(MenuItemImages[i], 3 * i * UI.MenuItemWidth, 0, UI.MenuItemWidth * 2, UI.ToolBarHeight);
	pWind->DrawImage(MenuItemImages[ITM_EXIT_PLAY], UI.width - UI.MenuItemWidth * 2, 0, UI.MenuItemWidth * 2, UI.ToolBarHeight);
	pWind->DrawImage(MenuItemImages[SWITCH_DRAW], UI.width - UI.MenuItemWidth * 2 * 2, 0, UI.MenuItemWidth * 2, UI.ToolBarHeight);

	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	/*end_output_play_mode*/
	///TODO: write code to create Play mode menu
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//



void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}


void Output::DrawSquare(Point P1, GfxInfo squareGfxInfo, bool selected) const
{
	const int length = 200;
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = squareGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (squareGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(squareGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle((P1.x) - length, (P1.y) - length, (P1.x) + length, (P1.y) + length, style);
	CreateDrawToolBar();
}
void Output::DrawTrig(Point P1, Point P2, Point P3, GfxInfo TrigGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TrigGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TrigGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TrigGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
	
}

void Output::DrawHexa(Point P1, GfxInfo HexaGfxInfo, bool selected) const
{
	float l = 100;
	int X[6];
	int Y[6];
	X[3] = (P1.x) + l;
	X[0] = (P1.x) - l;
	Y[0] = Y[3] = P1.y;
	X[1] = X[5] = (P1.x) - (l / 2);
	X[2] = X[4] = (P1.x) + (l / 2);
	Y[4] = Y[5] = (P1.y) + (0.8660254 * l);
	Y[1] = Y[2] = (P1.y) - (0.8660254 * l);
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = HexaGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (HexaGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(HexaGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawPolygon(X, Y, 6, style);
	CreateDrawToolBar();
}

void Output::DrawCircle(Point P1, Point P2, GfxInfo circleGfxInfo, bool selected) const
{
	float Radius = sqrt(pow((P1.x) - (P2.x), 2) + pow((P1.y) - (P2.y), 2));
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = circleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (circleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(circleGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawCircle(P1.x, P1.y, Radius, style);
	CreateDrawToolBar();
}


//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

