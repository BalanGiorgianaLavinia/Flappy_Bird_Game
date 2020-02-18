#include "Tema1.h"

#include <vector>
#include <iostream>

#include <Core/Engine.h>
#include "Transform2D.h"
#include "Object2D.h"
#include <ctime>

using namespace std;

Tema1::Tema1()
{
}

Tema1::~Tema1()
{
}


double doubleRand() {
	srand(static_cast<unsigned int>(clock()));
	return double(rand()) / (double(RAND_MAX) + 1.0);
}

void Tema1::Init()
{
	resolution = window->GetResolution();
	auto camera = GetSceneCamera();
	camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
	camera->SetPosition(glm::vec3(0, 0, 50));
	camera->SetRotation(glm::vec3(0, 0, 0));
	camera->Update();
	GetCameraInput()->SetActive(false);

	

	//initializare factori
	///////////////////////////////////////// pentru pasare ////////////////////////////////////////////////	
	translateYbird = 0.0f;									//miscarea pasarii sus-jos; initial sta pe loc

	scaleXbird = 5.0f;
	scaleYbird = 5.0f;

	//pozitia pasarii pe axa Oy pentru a verifica cand iese din ecran
	//pasarea este randata la inceput aproximativ cu centrul de greutate 
	//in originea sistemului de greutate, adica 0 pe Oy 
	birdPositionY = 0.0f;

	birdPositionX = resolution.x / 2;	//centrul de greutate al pasarii este mereu in mijlocul lui Ox

	angularStepBird = 3.1415f;		//factori pentru rotire
	angleBird = 0.0f;




	//////////////////////////////////////// pentru turnuri /////////////////////////////////////////////////
	translateXturn = resolution.x;							//pt prima pereche de turnuri
	translateXturn1 = resolution.x + (resolution.x / 2);	//pt a doua pereche de turnuri

	scaleXturn = resolution.x / 25;							//latimea turnurilor
	scaleYturn = resolution.y / 20;							//folosit la inaltimea turnurilor

	//factorii cu care o sa scalez perechile de turnuri sus-jos 
	//pentru a avea diversitate
	//am observat ca un factor de scalare de 2.8 este pentru tot ecranul
	//am considerat ca distanta dintre cele doua turnuri din perechi sa fie 0.8
	factorDown = 0.1 + doubleRand() * 2.0;
	factorUp = 2.2f - factorDown;

	factorDown1 = 0.1 + doubleRand() * 2.0;
	factorUp1 = 2.2f - factorDown1;





	//////////////////////////////////////// pentru iarba ///////////////////////////////////////////////
	scaleXiarba = 80.0f;
	scaleYiarba = 50.0f;

	translateXiarba = 2.5f * 80.0f;	//dimensiune x iarba * scalare X 



	////////////////////////////////////// pentru munte ////////////////////////////////////////////////
	scaleXmunte = 60.0f;
	scaleYmunte = 35.0f;





	/******************************************* PASARE *****************************************/
	{
		vector<VertexFormat> vertices
		{
			VertexFormat(glm::vec3(-4.25, -1.05,  0),	glm::vec3(1, 1, 1)),//0 A
			VertexFormat(glm::vec3(-3, 1,  0),			glm::vec3(1, 1, 1)),//1 B
			VertexFormat(glm::vec3(0, 3,  0),			glm::vec3(1, 1, 1)),//2 C 
			VertexFormat(glm::vec3(-6.39, -2.05,  0),	glm::vec3(1, 1, 1)),//3 D
			VertexFormat(glm::vec3(-6.23, -2.43,  0),	glm::vec3(0, 0, 1)),//4 E
			VertexFormat(glm::vec3(-3.73, -1.55,  0),	glm::vec3(0, 0, 1)),//5 F 
			VertexFormat(glm::vec3(-1.65, -2.65,  0),	glm::vec3(0, 0, 1)),//6 G
			VertexFormat(glm::vec3(0.39, -2.29,  0),	glm::vec3(0, 0, 1)),//7 H
			VertexFormat(glm::vec3(1.11, -1.27,  0),	glm::vec3(0, 0, 1)),//8 I
			VertexFormat(glm::vec3(1.47, -0.71,  0),	glm::vec3(0, 0, 1)),//9 J 
			VertexFormat(glm::vec3(1.83, 0.25,  0),		glm::vec3(0, 0, 1)),//10 K
			VertexFormat(glm::vec3(2.03, 1.51,  0),		glm::vec3(0, 0, 1)),//11 L
			VertexFormat(glm::vec3(2.11, 2.53,  0),		glm::vec3(0, 0, 1)),//12 M 
			VertexFormat(glm::vec3(0.13, 3.87,  0),		glm::vec3(1, 0, 0)),//13 N
			VertexFormat(glm::vec3(0.51, 4.37,  0),		glm::vec3(1, 0, 0)),//14 O
			VertexFormat(glm::vec3(1.03, 4.67,  0),		glm::vec3(1, 0, 0)),//15 P
			VertexFormat(glm::vec3(1.63, 4.63,  0),		glm::vec3(1, 0, 0)),//16 Q
			VertexFormat(glm::vec3(2.15, 4.43,  0),		glm::vec3(1, 0, 0)),//17 R 
			VertexFormat(glm::vec3(2.51, 3.87,  0),		glm::vec3(0, 0, 0)),//18 S
			VertexFormat(glm::vec3(2.59, 3.53,  0),		glm::vec3(0, 0, 0)),//19 T 
			VertexFormat(glm::vec3(3.35, 3.01,  0),		glm::vec3(1, 1, 0)),//20 U
			VertexFormat(glm::vec3(2.49, 2.91,  0),		glm::vec3(1, 1, 0)),//21 V 
			VertexFormat(glm::vec3(-1.41, -3.51,  0),	glm::vec3(0, 0, 1)),//22 W
			VertexFormat(glm::vec3(-0.98, -2.53,  0),	glm::vec3(0, 0, 1)),//23 Z

			VertexFormat(glm::vec3(-0.46, -2.44,  0),	glm::vec3(0, 0, 1)),//24 A1
			VertexFormat(glm::vec3(0, -3,  0),			glm::vec3(0, 0, 1)),//25 B1
			VertexFormat(glm::vec3(-0.1, -2.38,  0),	glm::vec3(0, 0, 1)),//26 C1
			VertexFormat(glm::vec3(2.22, 3.29,  0),		glm::vec3(1, 1, 0)),//27 D1 
			VertexFormat(glm::vec3(1.71, 3.91,  0),		glm::vec3(1, 0, 0)),//28 E1 
			VertexFormat(glm::vec3(1.22, 2.73,  0),		glm::vec3(1, 0, 0)), //29 F1 
			VertexFormat(glm::vec3(0.15, 0.81,  0),		glm::vec3(1, 1, 1)), //30 G1 
			VertexFormat(glm::vec3(-1.79, -0.38,  0),	glm::vec3(1, 1, 1)), //31 H1 
			VertexFormat(glm::vec3(-6.27, -2.33,  0),	glm::vec3(1, 1, 1)), //32 I1 

			VertexFormat(glm::vec3(-6.27, -2.33,  0),	glm::vec3(0, 0, 1)), //33 i1
			VertexFormat(glm::vec3(-3.96, -1.33,  0),	glm::vec3(0, 0, 1)), //34 j 
			VertexFormat(glm::vec3(-1.79, -0.38,  0),	glm::vec3(0, 0, 1)), //35 h1 
			VertexFormat(glm::vec3(0.15, 0.81,  0),		glm::vec3(0, 0, 1)), //36 g1 
			VertexFormat(glm::vec3(1.22, 2.73,  0),		glm::vec3(0, 0, 0)), //37 f1 
			VertexFormat(glm::vec3(2.11, 2.53,  0),		glm::vec3(0, 0, 0)), //38 m 
			VertexFormat(glm::vec3(2.22, 3.29,  0),		glm::vec3(0, 0, 0)), //39 d1 
			VertexFormat(glm::vec3(2.49, 2.91,  0),		glm::vec3(0, 0, 0)), //40 v 
			VertexFormat(glm::vec3(2.59, 3.53,  0),		glm::vec3(1, 1, 0)), //41 t 
			VertexFormat(glm::vec3(1.71, 3.91,  0),		glm::vec3(0, 0, 0)), //42 e1 
			VertexFormat(glm::vec3(2.15, 4.43,  0),		glm::vec3(0, 0, 0)), //43 r 
			VertexFormat(glm::vec3(1.22, 2.73,  0),		glm::vec3(1, 1, 1)), //44 f2 
			VertexFormat(glm::vec3(1.22, 2.73,  0),		glm::vec3(0, 0, 1)), //45 f3 
			VertexFormat(glm::vec3(-0.1, -2.38,  0),	glm::vec3(1, 0, 0)), //46 c 
			VertexFormat(glm::vec3(-3.96, -1.33,  0),	glm::vec3(1, 1, 1)) //47 J 
		};

		vector<unsigned short> indices{
			0, 3, 32,
			0, 32, 47,
			34, 33, 5,
			5, 33, 4,
			1, 0, 31,
			31, 0, 47,
			35, 34, 5,
			30, 1, 31,
			35, 5, 6,
			35, 6, 23,
			35, 23, 24,
			35, 24, 26,
			35, 26, 7,
			35, 7, 8,
			35, 8, 36,
			36, 8, 9,
			36, 9, 10,
			35, 10, 11,
			35, 11, 45,
			45, 11, 12,
			2, 1, 30,
			2, 30, 44,
			46, 29, 28,
			28, 13, 46,
			28, 14, 13,
			28, 15, 14,
			28, 16, 15,
			28, 17, 16,
			42, 37, 38,
			42, 38, 40,
			42, 39, 19,
			42, 19, 18,
			42, 18, 43,
			27, 21, 20,
			27, 20, 41,
			6, 22, 23,
			24, 25, 26
		};

		meshes["bird"] = new Mesh("generated bird");
		meshes["bird"]->InitFromData(vertices, indices);

		// Create a new mesh from buffer data
		Mesh *bird = CreateMesh("bird", vertices, indices);
	}


	//extrag coordonatele minime si maxime
	//intre care se gaseste pasarea in origine
	minXbird = -6.39 ; 
	maxXbird = 3.01 ;	
	minYbird = -3.51 ;	
	maxYbird = 4.67 ;	

	



	/****************************************** ARIPA ********************************************/
	{
		vector<VertexFormat> vertices{
			VertexFormat(glm::vec3(-4.21, 2.02,  0),		glm::vec3(0,0,1)),//a0
			VertexFormat(glm::vec3(-2, -0.74,  0),			glm::vec3(0,0,1)),//b1
			VertexFormat(glm::vec3(-5.15, 0.11,  0),		glm::vec3(0,0,1)),//c2
			VertexFormat(glm::vec3(-6.15, 0.98,  0),		glm::vec3(0,0,1)),//d3
			VertexFormat(glm::vec3(-6.26, 2.34,  0),		glm::vec3(0,0,1)),//e4
			VertexFormat(glm::vec3(-5.43, 3.4,  0),			glm::vec3(0,0,1)),//f5
			VertexFormat(glm::vec3(-3.65, 3.5,  0),			glm::vec3(0,0,1)),//g6
			VertexFormat(glm::vec3(-2, 3,  0),				glm::vec3(0,0,1)),//h7
			VertexFormat(glm::vec3(0.73, 1.21,  0),			glm::vec3(0,0,1))//i8	
		};
		vector<unsigned short> indices{
			0,8,7,
			0,7,6,
			0,6,5,
			0,5,4,
			0,4,3,
			0,3,2,
			0,2,1,
			0,1,8
		};
		meshes["aripa"] = new Mesh("generated aripa");
		meshes["aripa"]->InitFromData(vertices, indices);

		Mesh *aripa = CreateMesh("aripa", vertices, indices);
	}



	/****************************************** TURN ********************************************/
	{
		vector<VertexFormat> vertices
		{
			VertexFormat(glm::vec3(0.5, 0,  0), glm::vec3(0.5, 0.3, 0.1)),//0
			VertexFormat(glm::vec3(2.5, 0,  0), glm::vec3(0.7, 0.5, 0)),//1
			VertexFormat(glm::vec3(2.5, 6,  0), glm::vec3(0.5, 0.3, 0.1)),//2
			VertexFormat(glm::vec3(0.5, 6,  0), glm::vec3(0.7, 0.5, 0)),//3

			VertexFormat(glm::vec3(0, 6,  0),	glm::vec3(0.5, 0.3, 0.1)),//4
			VertexFormat(glm::vec3(3, 6,  0),	glm::vec3(0.5, 0.3, 0.1)),//5
			VertexFormat(glm::vec3(3, 6.5,  0), glm::vec3(0.5, 0.3, 0.1)),//6
			VertexFormat(glm::vec3(0, 6.5,  0), glm::vec3(0.5, 0.3, 0.1)),//7
		};

		vector<unsigned short> indices
		{
			0, 1, 2,
			0, 2, 3,
			4, 5, 6,
			6, 7, 4
		};

		meshes["turn"] = new Mesh("generated turn");
		meshes["turn"]->InitFromData(vertices, indices);

		Mesh *turn = CreateMesh("turn", vertices, indices);
	}

	turnWidth = 3.0f;							//extrag latime initiala turnuri

	initialTurnPosition = 6.5f;					//inaltimea maxima a turnului nescalat
	normalTurnPosition = initialTurnPosition;
	inversTurnPosition = initialTurnPosition;
	normalTurn1Position = initialTurnPosition;
	inversTurn1Position = initialTurnPosition;




	/****************************************** IARBA ********************************************/
	{
		vector<VertexFormat> vertices{
			VertexFormat(glm::vec3(0, 0,  0),		glm::vec3(0.2, 0.6, 0.3)),//a0
			VertexFormat(glm::vec3(2, 0,  0),		glm::vec3(0.2, 0.6, 0.3)),//c1
			VertexFormat(glm::vec3(1, 4,  0),		glm::vec3(0.2, 0.6, 0.3)),//b2
			VertexFormat(glm::vec3(1.25, 3,  0),	glm::vec3(0.2, 0.6, 0.3)),//d3
			VertexFormat(glm::vec3(1.5, 4.5,  0),	glm::vec3(0.2, 0.6, 0.3)),//e4
			VertexFormat(glm::vec3(1.74, 1.04,  0),	glm::vec3(0.2, 0.6, 0.3)),//f5
			VertexFormat(glm::vec3(1.71, 1.53,  0), glm::vec3(0.2, 0.6, 0.3)),//g6
			VertexFormat(glm::vec3(2, 4,  0),		glm::vec3(0.2, 0.6, 0.3)),//h7
			VertexFormat(glm::vec3(2, 1,  0),		glm::vec3(0.2, 0.6, 0.3)),//i8
			VertexFormat(glm::vec3(2.5, 4.5,  0),	glm::vec3(0.2, 0.6, 0.3)),//j9
			VertexFormat(glm::vec3(3, 0,  0),		glm::vec3(0.2, 0.6, 0.3))//k10
		};
		vector<unsigned short> indices{
			0, 1, 2, 
			5, 4, 3, 
			1, 7, 6, 
			1, 10, 8, 
			10, 9, 8
		};
		meshes["iarba"] = new Mesh("generated iarba");
		meshes["iarba"]->InitFromData(vertices, indices);

		Mesh *iarba = CreateMesh("iarba", vertices, indices);
	}



	/****************************************** MUNTE ********************************************/
	{
		vector<VertexFormat> vertices{
			VertexFormat(glm::vec3(3.11, 14.25,  0),		glm::vec3(0.3, 0.4, 0.5)),//a0
			VertexFormat(glm::vec3(0, 12,  0),				glm::vec3(0.3, 0.4, 0.5)),//b1
			VertexFormat(glm::vec3(4.85, 12.24,  0),		glm::vec3(0.3, 0.4, 0.5)),//c2
			VertexFormat(glm::vec3(9.86, 18.62,  0),		glm::vec3(0.3, 0.4, 0.5)),//d3
			VertexFormat(glm::vec3(18, 8,  0),				glm::vec3(0.3, 0.4, 0.5)),//e4
			VertexFormat(glm::vec3(12.50, 14.97,  0),		glm::vec3(0.3, 0.4, 0.5)),//f5
			VertexFormat(glm::vec3(16.99, 18.28,  0),		glm::vec3(0.3, 0.4, 0.5)),//g6
			VertexFormat(glm::vec3(25, 10,  0),				glm::vec3(0.3, 0.4, 0.5)),//h7
			VertexFormat(glm::vec3(0 , 0,  0),				glm::vec3(0.3, 0.4, 0.5)),//i8
			VertexFormat(glm::vec3(25, 0,  0),				glm::vec3(0.3, 0.4, 0.5)),//j9
			VertexFormat(glm::vec3(7.88 , 16.1,  0),		glm::vec3(0.3, 0.4, 0.5)),//k10
			VertexFormat(glm::vec3(8.54, 14.94,  0),		glm::vec3(0.3, 0.4, 0.5)),//l11
			VertexFormat(glm::vec3(9.71, 16.44,  0),		glm::vec3(1,1,1)),//m12
			VertexFormat(glm::vec3(13.36, 14.06,  0),		glm::vec3(0.3, 0.4, 0.5)),//n13
			VertexFormat(glm::vec3(9.86, 18.62,  0),		glm::vec3(1,1,1)),//D14
			VertexFormat(glm::vec3(12.50, 14.97,  0),		glm::vec3(0.3, 0.4, 0.5)),//F15
			VertexFormat(glm::vec3(16.99, 18.28,  0),		glm::vec3(1,1,1)),//G16
			VertexFormat(glm::vec3(15.03 , 16.78,  0),		glm::vec3(1,1,1)),//o17
			VertexFormat(glm::vec3(15.4, 16.03,  0),		glm::vec3(0.95, 0.95, 0.95)),//p18
			VertexFormat(glm::vec3(15.79, 16.58,  0),		glm::vec3(1,1,1)),//q19
			VertexFormat(glm::vec3(17.38, 17.88,  0),		glm::vec3(1,1,1)),//r20
			VertexFormat(glm::vec3(15.01, 14.02,  0),		glm::vec3(0.7,0.7,0.7)),//s21
			VertexFormat(glm::vec3(16.24, 16.95,  0),		glm::vec3(0.9,0.9,0.9)),//t22
			VertexFormat(glm::vec3(18, 16,  0),				glm::vec3(0.7,0.7,0.7)),//u23
			VertexFormat(glm::vec3(18.16, 17.08,  0),		glm::vec3(0.7,0.7,0.7)),//v24
			VertexFormat(glm::vec3(3.11, 14.25,  0),		glm::vec3(1,1,1)),//A25
			VertexFormat(glm::vec3(2.08, 13.51,  0),		glm::vec3(0.8,0.8,0.8)),//w26
			VertexFormat(glm::vec3(3.48, 13.83,  0),		glm::vec3(0.9,0.9,0.9))//z27
		};
		vector<unsigned short> indices{
			25,26,27,
			17,21,18,
			18,21,19, 
			17,15,21,
			17,15,18,
			17,18,16,
			16,19,20,
			20,22,24,
			22,23,24,
			10,11,12,
			12,13,14,
			10,12,14,
			0,1,2,
			3,2,4,
			5,4,7,
			5,7,6,
			1,4,2,
			8,4,1,
			8,9,4,
			4,9,7
		};
		meshes["munte"] = new Mesh("generated munte");
		meshes["munte"]->InitFromData(vertices, indices);

		Mesh *munte = CreateMesh("munte", vertices, indices);
	}

}




void Tema1::FrameStart()
{
	glClearColor(0.2, 0.9, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	glViewport(0, 0, resolution.x, resolution.y);
}



void Tema1::Update(float deltaTimeSeconds)
{
		//actualizez factorii

		angleBird += deltaTimeSeconds * (angularStepBird - 1.25f);

		if (angularStepBird > 3.14f	/ 8.0f)		
			angularStepBird -= 3.14f / 8.0f;
		else	
			angularStepBird = 0.0f;


		//limitele pana la care se roteste in sus sau in jos
		if (angleBird > 3.14f / 10.0f)			angleBird = 3.14f / 10.0f;
		if (angleBird < -3.14f / 2.0f)			angleBird = -3.14f / 2.0f;


		//dificultate joc => deplasarea turnurilor catre stanga
		if (score >= 30) {
			translateXturn -= deltaTimeSeconds * (resolution.x / 2.0f);
			translateXturn1 -= deltaTimeSeconds * (resolution.x / 2.0f);
		}else {
			if (score >= 15) {
				translateXturn -= deltaTimeSeconds * (resolution.x / 3.0f);
				translateXturn1 -= deltaTimeSeconds * (resolution.x / 3.0f);
			}else {
				translateXturn -= deltaTimeSeconds * (resolution.x / 4.5f);
				translateXturn1 -= deltaTimeSeconds * (resolution.x / 4.5f);
			}
		}
		

		minXbird = -6.39;
		maxXbird = 3.01;
		minYbird = -3.51;
		maxYbird = 4.67;


		/**************************************RANDEZ ARIPA************************************/
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(0.0f, translateYbird);
		modelMatrix *= Transform2D::Translate(birdPositionX, resolution.y / 2);
		if (acceleration <= 0) {
			modelMatrix *= Transform2D::Rotate(-3.14f / 2.0f);
			modelMatrix *= Transform2D::Scale(scaleXbird, scaleYbird / 1.5f);
		}else {
			modelMatrix *= Transform2D::Rotate(3.14f / 5.0f);
			modelMatrix *= Transform2D::Scale(scaleXbird, -scaleYbird / 1.5f);
		}
		RenderMesh2D(meshes["aripa"], shaders["VertexColor"], modelMatrix);


		/**************************************RANDEZ PASAREA************************************/
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(0.0f, translateYbird);
		modelMatrix *= Transform2D::Translate(birdPositionX, resolution.y / 2);//la mijlocul ecranului
		modelMatrix *= Transform2D::Scale(scaleXbird, scaleYbird);
		//rotesc pasarea cu ciocul in sus cand urca sau in jos cand coboara
		modelMatrix *= Transform2D::Rotate(angleBird);
		RenderMesh2D(meshes["bird"], shaders["VertexColor"], modelMatrix);

		//actualizez cele 4 coordonate N-S, E-V intre care se gaseste pasarea 
		minXbird *= scaleXbird;		minXbird += birdPositionX;									// V
		maxXbird *= scaleXbird;		maxXbird += birdPositionX;									// E
		minYbird *= scaleYbird;		minYbird += resolution.y / 2;	minYbird += translateYbird;	// S
		maxYbird *= scaleYbird;		maxYbird += resolution.y / 2;	maxYbird += translateYbird;	// N


		birdPositionY = 0.0f;
		birdPositionY *= scaleYbird;
		birdPositionY += resolution.y / 2;
		birdPositionY += translateYbird;
		
		//daca pasarea iese din ecran se opreste jocul
		if (birdPositionY + maxYbird < 0 ||
			birdPositionY - minYbird > resolution.y) {
					cout << endl <<  "Game over!!! :( " << endl;
					cout << "Scorul tau final este: " << score << endl;
					exit(-1);
		}

		translateYbird += deltaTimeSeconds * acceleration;
		acceleration -= resolution.y / 36;	//prinde viteza cand coboara -> forta de greutate
		




		/************************************** RANDEZ TURN JOS ********************************/
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(translateXturn, 0);
		modelMatrix *= Transform2D::Scale(scaleXturn, factorDown * scaleYturn);
		RenderMesh2D(meshes["turn"], shaders["VertexColor"], modelMatrix);

		//verific coliziune
		normalTurnPosition = initialTurnPosition;
		normalTurnPosition *= factorDown * scaleYturn;
		if ( minYbird < normalTurnPosition &&
			 maxXbird > translateXturn && 
			 minXbird < (translateXturn + turnWidth * scaleXturn)) {
				cout << endl <<  "Game over!!! :( " << endl;
				cout << "Scorul tau final este: " << score << endl;
				exit(-2);
		}
	

		/************************************** RANDEZ TURN SUS ********************************/
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(translateXturn, resolution.y);
		modelMatrix *= Transform2D::Scale(scaleXturn, -1.0f * factorUp * scaleYturn);
		RenderMesh2D(meshes["turn"], shaders["VertexColor"], modelMatrix);

		//verific coliziune
		inversTurnPosition = initialTurnPosition;
		inversTurnPosition *= -1.0f * factorUp * scaleYturn;
		inversTurnPosition += resolution.y;
		if (maxYbird > inversTurnPosition &&
			 maxXbird > translateXturn &&
			 minXbird < (translateXturn + turnWidth * scaleXturn)) {
				cout << endl << "Game over!!! :( " << endl;
				cout << "Scorul tau final este: " << score << endl;
				exit(-2);
		}


		//			SCOR
		if (counted == 0 && minXbird > translateXturn + turnWidth * scaleXturn) {
			counted = 1;
			score++;
			cout << "Scor: " << score << "!" << endl;
		}



		/************************************** RANDEZ TURN JOS 1 ********************************/
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(translateXturn1, 0);
		modelMatrix *= Transform2D::Scale(scaleXturn, factorDown1 * scaleYturn);
		RenderMesh2D(meshes["turn"], shaders["VertexColor"], modelMatrix);

		//verific coliziune
		normalTurn1Position = initialTurnPosition;
		normalTurn1Position *= factorDown1 * scaleYturn;
		if ( minYbird < normalTurn1Position &&
			maxXbird > translateXturn1 &&
			minXbird < (translateXturn1 + turnWidth * scaleXturn)) {
				cout << endl <<  "Game over!!! :( " << endl;
				cout << "Scorul tau final este: " << score << endl;
				exit(-2);
		}



		/************************************** RANDEZ TURN SUS 1 ********************************/
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(translateXturn1, resolution.y);
		modelMatrix *= Transform2D::Scale(scaleXturn, -1.0f * factorUp1 * scaleYturn);
		RenderMesh2D(meshes["turn"], shaders["VertexColor"], modelMatrix);

		//verific coliziune
		inversTurn1Position = initialTurnPosition;
		inversTurn1Position *= -1.0f * factorUp1 * scaleYturn;
		inversTurn1Position += resolution.y;
		if ( maxYbird > inversTurn1Position &&
			maxXbird > translateXturn1 &&
			 minXbird < (translateXturn1 + turnWidth * scaleXturn)) {
				cout << endl << "Game over!!! :( " << endl;
				cout << "Scorul tau final este: " << score << endl;
				exit(-2);
		}



		//			SCOR
		if (counted1 == 0 && minXbird > translateXturn1 + turnWidth * scaleXturn) {
			counted1 = 1;
			score++;
			cout << "Scor: " << score << "!" << endl;
		}


		/************************************** RANDEZ IARBA ********************************/
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Scale(scaleXiarba, scaleYiarba);
		RenderMesh2D(meshes["iarba"], shaders["VertexColor"], modelMatrix);

		//randez de 7 ori
		for (int i = 0; i < 7; i++) {
			modelMatrix = glm::mat3(1);
			modelMatrix *= Transform2D::Translate(i * translateXiarba, 0.0f);
			modelMatrix *= Transform2D::Scale(scaleXiarba, scaleYiarba);
			RenderMesh2D(meshes["iarba"], shaders["VertexColor"], modelMatrix);

		}

		/************************************** RANDEZ MUNTE ********************************/
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Scale(scaleXmunte, scaleYmunte);
		RenderMesh2D(meshes["munte"], shaders["VertexColor"], modelMatrix);





		//cand dispare o pereche de turnuri din ecran o randez din nou 
		//la finalul ecranului cu o alta scalare pe Oy
		if (translateXturn <= -turnWidth * scaleXturn) {
			translateXturn = resolution.x;
			factorDown = 0.1f + doubleRand() * 2.0f;
			factorUp = 2.2f - factorDown;

			counted = 0;
		}
		if (translateXturn1 <= -turnWidth * scaleXturn) {
			translateXturn1 = resolution.x;
			factorDown1 = 0.1f + doubleRand() * 2.0f;
			factorUp1 = 2.2f - factorDown1;

			counted1 = 0;
		}

}






Mesh* Tema1::CreateMesh(const char *name, const std::vector<VertexFormat> &vertices, const std::vector<unsigned short> &indices)
{
	unsigned int VAO = 0;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	unsigned int VBO = 0;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

	unsigned int IBO = 0;
	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * indices.size(), &indices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), 0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(sizeof(glm::vec3)));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(2 * sizeof(glm::vec3)));

	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(2 * sizeof(glm::vec3) + sizeof(glm::vec2)));

	glBindVertexArray(0);

	CheckOpenGLError();

	meshes[name] = new Mesh(name);
	meshes[name]->InitFromBuffer(VAO, static_cast<unsigned short>(indices.size()));
	return meshes[name];
}





void Tema1::FrameEnd()
{

}

void Tema1::OnInputUpdate(float deltaTime, int mods)
{

}

void Tema1::OnKeyPress(int key, int mods)
{
	if (key == GLFW_KEY_SPACE) {
		acceleration = resolution.y / 1.6f;
		angularStepBird = 3.14f * 2.0f;
	}
}

void Tema1::OnKeyRelease(int key, int mods)
{
	// add key release event
}

void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	// add mouse move event
}

void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button press event
}

void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button release event
}

void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Tema1::OnWindowResize(int width, int height)
{
}
