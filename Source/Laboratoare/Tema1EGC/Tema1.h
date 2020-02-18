#pragma once

#include <Component/SimpleScene.h>
#include <string>
#include <Core/Engine.h>

class Tema1 : public SimpleScene
{
	public:
		Tema1();
		~Tema1();

		void Init() override;

	private:
		void FrameStart() override;
		void Update(float deltaTimeSeconds) override;
		void FrameEnd() override;

		void OnInputUpdate(float deltaTime, int mods) override;
		void OnKeyPress(int key, int mods) override;
		void OnKeyRelease(int key, int mods) override;
		void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
		void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
		void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
		void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
		void OnWindowResize(int width, int height) override;

		Mesh* CreateMesh(const char *name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned short>& indices);

	protected:
		glm::mat3 modelMatrix;
		GLenum polygonMode;
		glm::ivec2 resolution;

		//////////////general
		int score = 0;
		int counted, counted1;

		/////////////pentru pasare
		float minXbird, maxXbird, minYbird, maxYbird;
		float virtualCircleRadius;
		float translateYbird;
		float birdPositionY, birdPositionX;
		float scaleXbird, scaleYbird;

		float acceleration;
		float angularStepBird, angleBird;




		//////////////pentru turnuri
		float translateXturn, translateXturn1;
		float scaleXturn, scaleYturn;

		float factorUp, factorDown;
		float factorUp1, factorDown1;

		float turnWidth;

		float initialTurnPosition;
		float normalTurnPosition ;
		float inversTurnPosition ;
		float normalTurn1Position;
		float inversTurn1Position;



		///////////////pentru iarba
		float scaleXiarba, scaleYiarba;
		float translateXiarba;

		//////////////pentru munte
		float scaleXmunte, scaleYmunte;





	
};
