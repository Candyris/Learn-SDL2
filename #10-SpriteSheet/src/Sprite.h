#pragma once
#include <SDL2/SDL.h>

class Vector2i {
public:
	Vector2i(int p_X ,int p_Y) : x(p_X) , y (p_Y){}
	int x, y;
};

class Sprite
{
public:
	Sprite();
	Sprite(const char* filePath,Vector2i srcSpritePosition, Vector2i dsntSpritePosition);
	//Sprite(const char* filePath, Vector2i srcPosition, Vector2i dsntPosition);
	~Sprite();
	
	// setters
	void setPosition(Vector2i p_Position);
	void setSize(Vector2i p_Size);
	void loadTexture(const char* p_FilePath);
	// getters
	Vector2i getPosition();
	Vector2i getSize();

	//void setOrgin();
	virtual void update(int p_DeltaTime) = 0;
	virtual void render();
protected:
	SDL_Texture* m_SpriteTexture;
	SDL_RendererFlip m_SpriteFlip;
	int m_SpriteAngle;
private:
	SDL_Rect m_SpriteSrcRect;
	SDL_Rect m_SpritedsntRect;
};

