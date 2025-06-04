#ifndef FRECT
#define FRECT

#include <SDL3/SDL.h>
#include <iostream>
#include <texture.hpp>
#include <text.hpp>

using namespace std;

/**
 * @brief Class for representing and managing a rectangle with color, text, or textures
 * 
 * Allows setting position, size, color, textures, text, checking intersections, and interactions with the mouse
 */
class frect {
    private:
        struct colorStruct {
            Uint8 r = 0;
            Uint8 g = 0;
            Uint8 b = 0;
            Uint8 alpha = 255;
        };

        struct frectData {
            SDL_FRect frect;
            colorStruct color;
        };

        frectData data;
    public:
        /**
         * @brief Constructor with position and size parameters
         * 
         * @param x X coordinate from the top left corner
         * @param y Y coordinate from the top left corner
         * @param w Width of the rectangle
         * @param h Height of the rectangle
         */
        frect(float x = 0, float y = 0, float w = 0, float h = 0) {
            data.frect.x = x;
            data.frect.y = y;
            data.frect.w = w;
            data.frect.h = h;
        }
        
        /**
         * @brief Sets the position and size of the rectangle
         * 
         * @param x X coordinate from the top left corner
         * @param y Y coordinate from the top left corner
         * @param w Width of the rectangle
         * @param h Height of the rectangle
         */
        void setFrect(float x, float y, float w, float h) {
            data.frect.x = x;
            data.frect.y = y;
            data.frect.w = w;
            data.frect.h = h;
        }

        /**
         * @brief Sets the position of the rectangle
         * 
         * @param x X coordinate from the top left corner
         * @param y Y coordinate from the top left corner
         */
        void setPosition(float x, float y) {
            data.frect.x = x;
            data.frect.y = y;
        }

        /**
         * @brief Sets the size of the rectangle
         * 
         * @param w Width of the rectangle
         * @param h Height of the rectangle
         */
        void setSize(float w, float h) {
            data.frect.w = w;
            data.frect.h = h;
        }

        /** @brief Sets the X coordinate from the top left corner */
        void setX(float x){ data.frect.x = x; }
        /** @brief Sets the Y coordinate from the top left corner */
        void setY(float y){ data.frect.y = y; }
        /** @brief Sets the width of the rectangle */
        void setWidth(float w){ data.frect.w = w; }
        /** @brief Sets the height of the rectangle */
        void setHeight(float h){ data.frect.h = h; }

        /** @brief Increases the X coordinate by the specified value */
        void addX(float x){ data.frect.x += x; }
        /** @brief Increases the Y coordinate by the specified value */
        void addY(float y){ data.frect.y += y; }
        /** @brief Increases the width by the specified value */
        void addWidth(float w){ data.frect.w += w; }
        /** @brief Increases the height by the specified value */
        void addHeight(float h){ data.frect.h += h; }

        /** @brief Decreases the X coordinate by the specified value */
        void subX(float x){ data.frect.x -= x; }
        /** @brief Decreases the Y coordinate by the specified value */
        void subY(float y){ data.frect.y -= y; }
        /** @brief Decreases the width by the specified value */
        void subWidth(float w){ data.frect.w -= w; }
        /** @brief Decreases the height by the specified value */
        void subHeight(float h){ data.frect.h -= h; }

        /** @brief Returns the X coordinate of the top left corner */
        float getX(){ return data.frect.x; }
        /** @brief Returns the Y coordinate of the top left corner */
        float getY(){ return data.frect.y; }
        /** @brief Returns the width of the rectangle */
        float getWidth(){ return data.frect.w; }
        /** @brief Returns the height of the rectangle */
        float getHeight(){ return data.frect.h; }

        /**
         * @brief Returns the frectData structure with the rectangle's parameters
         * 
         * @return frectData A copy of the internal rectangle structure
         */
        frectData get() {
            return data;
        }

                /**
         * @brief Fills the rectangle area on the renderer with the specified color
         * 
         * If color parameters are not set, current color values are used.
         * Or if you want to keep a specific color, specify -1
         * 
         * @param render Pointer to SDL_Renderer for drawing
         * @param r Red color component (0-255)
         * @param g Green color component (0-255)
         * @param b Blue color component (0-255)
         * @param alpha Alpha channel (0-255)
         */
        void fill(SDL_Renderer *render, Uint8 r = -1, Uint8 g = -1, Uint8 b = -1, Uint8 alpha = -1) {
            r = r == -1 ? data.color.r : r;
            b = b == -1 ? data.color.b : b;
            g = g == -1 ? data.color.g : g;
            alpha = alpha == -1 ? data.color.alpha : alpha;

            data.color.r = r;
            data.color.g = g;
            data.color.b = b;
            data.color.alpha = alpha;

            SDL_SetRenderDrawColor(render, r, g, b, alpha);
            SDL_RenderFillRect(render, &data.frect);
        }

        /**
         * @brief Renders a texture with rotation and flipping options
         * 
         * @param render Pointer to SDL_Renderer
         * @param texture Pointer to texture object
         * @param deg Rotation angle in degrees (clockwise)
         * @param mode Flip mode (SDL_FLIP_NONE, SDL_FLIP_HORIZONTAL, SDL_FLIP_VERTICAL)
         * @param point Rotation point (relative to the rectangle)
         */
        void fillTexture(SDL_Renderer *render, texture *texture, double deg = 0, SDL_FlipMode mode = SDL_FLIP_NONE, SDL_FPoint point = {0, 0}) {
            SDL_RenderTextureRotated(render, texture->get().texture, nullptr, &data.frect, deg, &point, mode);
        }

        /**
         * @brief Renders text inside the rectangle area
         * 
         * @param render Pointer to SDL_Renderer
         * @param text Pointer to text object
         */
        void fillText(SDL_Renderer *render, text *text) {
            SDL_RenderTexture(render, text->get().texture, nullptr, &data.frect);
        }

        /**
         * @brief Checks if the current rectangle intersects with another
         * 
         * @param otfrect Reference to another frect object for intersection check
         * @return true If rectangles intersect
         * @return false If no intersection
         */
        bool onTouch(frect& otfrect) {
            if (data.frect.x < otfrect.data.frect.x + otfrect.data.frect.w &&
                data.frect.x + data.frect.w > otfrect.data.frect.x &&
                data.frect.y < otfrect.data.frect.y + otfrect.data.frect.h &&
                data.frect.y + data.frect.h > otfrect.data.frect.y) {
                return true;
            }
            return false;
        }

        /**
         * @brief Checks if the mouse cursor is inside the rectangle
         * 
         * Gets the current mouse coordinates and checks if it is inside the rectangle area
         * 
         * @return true If the mouse is inside the rectangle
         * @return false Otherwise
         */
        bool onHover() {
            float mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);

            if (mouseX >= data.frect.x && mouseX <= data.frect.x + data.frect.w &&
                mouseY >= data.frect.y && mouseY <= data.frect.y + data.frect.h) {
                return true;
            }
            return false;
        }

        /**
         * @brief Overloads the output operator for convenient display of rectangle parameters
         * 
         * Outputs position, size, and color of the rectangle to the stream
         */
        friend ostream& operator<<(ostream& os, frect& r) {
            os << "FRect(x: " << r.data.frect.x << ", y: " << r.data.frect.y 
               << ", w: " << r.data.frect.w << ", h: " << r.data.frect.h 
               << ", r: " << static_cast<int>(r.data.color.r) 
               << ", g: " << static_cast<int>(r.data.color.g) 
               << ", b: " << static_cast<int>(r.data.color.b) 
               << ", alpha: " << static_cast<int>(r.data.color.alpha) << ")";
            return os;
        }
};

#endif