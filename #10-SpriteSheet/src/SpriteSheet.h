#pragma once
#include <SDL2/SDL.h>

class Vector2 {
public:
	Vector2(){ }
	Vector2(int x, int y) : m_X(x), m_Y(y) {}
	void setVector2(int x, int y) {
		m_X = x;
		m_Y = y;
	}
	Vector2* getVector2() { return this; }
private:
	int m_X, m_Y; 
};
class Sprite
{
public:
	Sprite(const char* p_Path, int p_Width, int p_Height);
	~Sprite();
	SDL_Texture* GetSprite(int p_X ,int p_Y);
	void draw(Vector2 p_Position,const SDL_Renderer* ren);
private:
	SDL_Rect     m_Clip;
	SDL_Surface* m_Sprite_image;
	Vector2 m_Size;
	SDL_Renderer* m_Renderer;
};

