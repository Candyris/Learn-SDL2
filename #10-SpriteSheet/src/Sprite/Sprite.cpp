#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "Sprite.h"

void Sprite::initVariable()
{
	// initialize the Default Value for Class
	m_SpriteAngle = SDL_FLIP_NONE;
	m_AxisPointRotatoAgainst = NULL;
	m_SpriteAngle = 0;

	// geometry of Sprite setting to 0
	m_SpriteSrcRect.x = 0;
	m_SpriteSrcRect.y = 0;
	m_SpriteSrcRect.w = 0;
	m_SpriteSrcRect.h = 0;

	m_SpriteDsntRect.x = 0;
	m_SpriteDsntRect.y = 0;
	m_SpriteDsntRect.w = SPRITE_SIZE;
	m_SpriteDsntRect.h = SPRITE_SIZE;
}

Sprite::Sprite(SDL_Renderer *p_Renderer, const char *p_FilePath, Vector2i p_SrcSpritePosition, Vector2i p_SrcSpriteSize)
{
	initVariable();
	// setting parmeter to class member
	m_Renderer = p_Renderer;
	m_SpriteTexture = IMG_LoadTexture(m_Renderer, p_FilePath);
	if (!m_SpriteTexture)
	{
		SDL_Log("Unable to load texture. SDL_image Error: %s\n", IMG_GetError());
	}

	// setting geometry of Sprite
	m_SpriteSrcRect.x = p_SrcSpritePosition.x;
	m_SpriteSrcRect.y = p_SrcSpritePosition.y;
	m_SpriteSrcRect.w = p_SrcSpriteSize.x;
	m_SpriteSrcRect.h = p_SrcSpriteSize.y;
}

Sprite::Sprite(SDL_Renderer *p_Renderer, const char *p_FilePath, Vector2i p_SrcSpritePosition, Vector2i p_SrcSpriteSize, Vector2i p_DsntSpritePosition)
{
	initVariable();
	// setting parmeter to class member
	m_Renderer = p_Renderer;
	m_SpriteAngle = SDL_FLIP_NONE;
	m_SpriteTexture = IMG_LoadTexture(m_Renderer, p_FilePath);
	if (!m_SpriteTexture)
	{
		SDL_Log("Unable to load texture. SDL_image Error: %s\n", IMG_GetError());
	}

	// setting geometry of Sprite
	m_SpriteSrcRect.x = p_SrcSpritePosition.x;
	m_SpriteSrcRect.y = p_SrcSpritePosition.y;
	m_SpriteSrcRect.w = p_SrcSpriteSize.x;
	m_SpriteSrcRect.h = p_SrcSpriteSize.y;

	m_SpriteDsntRect.x = p_DsntSpritePosition.x;
	m_SpriteDsntRect.y = p_DsntSpritePosition.y;
}

Sprite::Sprite(SDL_Renderer *p_Renderer, const char *p_FilePath, SDL_Rect srcRect, SDL_Rect dsntRect)
	: m_SpriteSrcRect(srcRect), m_SpriteDsntRect(dsntRect)
{
	initVariable();
	// setting parmeter to class member
	m_Renderer = p_Renderer;
	m_SpriteTexture = IMG_LoadTexture(m_Renderer, p_FilePath);
	if (!m_SpriteTexture)
	{
		SDL_Log("Unable to load texture. SDL_image Error: %s\n", IMG_GetError());
		return;
	}
}

Sprite::Sprite(SDL_Renderer *p_Renderer, const char *p_FilePath)
{
	initVariable();
	// setting parmeter to class member
	m_Renderer = p_Renderer;
	m_SpriteTexture = IMG_LoadTexture(m_Renderer, p_FilePath);
	if (!m_SpriteTexture)
	{
		SDL_Log("Unable to load texture. SDL_image Error: %s\n", IMG_GetError());
		return;
	}
	SDL_QueryTexture(m_SpriteTexture, NULL, NULL, &m_SpriteSrcRect.w, &m_SpriteSrcRect.h);
	m_SpriteDsntRect = {0, 0, m_SpriteSrcRect.w, m_SpriteSrcRect.h};
}

Sprite::~Sprite()
{
	if (m_AxisPointRotatoAgainst != nullptr)
	{
		delete m_AxisPointRotatoAgainst;
	}
	m_Renderer = nullptr;
	SDL_DestroyTexture(m_SpriteTexture);
}

void Sprite::render()
{
	if (m_SpriteSrcRect.w == 0 && m_SpriteSrcRect.h == 0)
	{
		SDL_RenderCopyEx(m_Renderer, m_SpriteTexture, NULL, &m_SpriteDsntRect, m_SpriteAngle, m_AxisPointRotatoAgainst, m_SpriteFlip);
	}
	else
	{
		SDL_RenderCopyEx(m_Renderer, m_SpriteTexture, &m_SpriteSrcRect, &m_SpriteDsntRect, m_SpriteAngle, m_AxisPointRotatoAgainst, m_SpriteFlip);
	}
}
// Setters
void Sprite::setSourceImageSize(Vector2i p_SrcImgPos)
{
	m_SpriteSrcRect.x = p_SrcImgPos.x;
	m_SpriteSrcRect.y = p_SrcImgPos.y;
}

void Sprite::setSourceImagePosition(Vector2i p_SrcImgSize)
{
	m_SpriteSrcRect.w = p_SrcImgSize.x;
	m_SpriteSrcRect.h = p_SrcImgSize.y;
}

void Sprite::setDrawPosition(Vector2i p_Position)
{
	m_SpriteDsntRect.x = p_Position.x;
	m_SpriteDsntRect.y = p_Position.y;
}

void Sprite::setDrawSize(Vector2i p_Size)
{
	m_SpriteDsntRect.w = p_Size.x;
	m_SpriteDsntRect.h = p_Size.y;
}

void Sprite::setRotate(int p_Angle)
{
	m_SpriteAngle = p_Angle;
}
void Sprite::setFlip(SDL_RendererFlip p_Flip)
{
	m_SpriteFlip = p_Flip;
}
void Sprite::setRotateAxis(SDL_Point centre)
{
	m_AxisPointRotatoAgainst = new SDL_Point;
	m_AxisPointRotatoAgainst->x = centre.x;
	m_AxisPointRotatoAgainst->y = centre.y;
}
// Getters
Vector2i Sprite::getDrawPosition()
{
	return Vector2i(m_SpriteSrcRect.x, m_SpriteSrcRect.y);
}

Vector2i Sprite::getDrawSize()
{
	return Vector2i(m_SpriteSrcRect.w, m_SpriteSrcRect.h);
}

Vector2i Sprite::getImgPosition()
{
	return Vector2i(m_SpriteDsntRect.x, m_SpriteDsntRect.y);
}

Vector2i Sprite::getImgSize()
{
	return Vector2i(m_SpriteDsntRect.w, m_SpriteDsntRect.h);
}

int Sprite::getRotate() const
{
	return m_SpriteAngle;
}

// loaders
void Sprite::loadTexture(const char *p_FilePath)
{
	SDL_DestroyTexture(m_SpriteTexture);
	m_SpriteTexture = IMG_LoadTexture(m_Renderer, p_FilePath);
	if (!m_SpriteTexture)
	{
		SDL_Log("Unable to load texture. SDL_image Error: %s\n", IMG_GetError());
	}
}
