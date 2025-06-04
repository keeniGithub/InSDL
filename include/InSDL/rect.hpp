#ifndef RECT
#define RECT

#include <SDL3/SDL.h>
#include <iostream>

using namespace std;

/**
 * @brief Class for representing and managing a rectangle with color
 * 
 * Allows setting position, size, color, checking intersections, and interactions with the mouse
 */
class rect {
    private:
        struct colorStruct {
            Uint8 r = 0;
            Uint8 g = 0;
            Uint8 b = 0;
        };

        struct rectData {
            SDL_Rect rect;
            colorStruct color;
        };

        rectData data;
    public:
        /**
         * @brief Constructor with position and size parameters
         * 
         * @param x X coordinate from the top left corner
         * @param y Y coordinate from the top left corner
         * @param w Width of the rectangle
         * @param h Height of the rectangle
         */
        rect(int x = 0, int y = 0, int w = 0, int h = 0) {
            data.rect.x = x;
            data.rect.y = y;
            data.rect.w = w;
            data.rect.h = h;
        }
        
        /**
         * @brief Sets the position and size of the rectangle
         * 
         * @param x X coordinate from the top left corner
         * @param y Y coordinate from the top left corner
         * @param w Width of the rectangle
         * @param h Height of the rectangle
         */
        void setRect(int x, int y, int w, int h) {
            data.rect.x = x;
            data.rect.y = y;
            data.rect.w = w;
            data.rect.h = h;
        }

        /**
         * @brief Sets the position of the rectangle
         * 
         * @param x X coordinate from the top left corner
         * @param y Y coordinate from the top left corner
         */
        void setPosition(int x, int y) {
            data.rect.x = x;
            data.rect.y = y;
        }

        /**
         * @brief Sets the size of the rectangle
         * 
         * @param w Width of the rectangle
         * @param h Height of the rectangle
         */
        void setSize(int w, int h) {
            data.rect.w = w;
            data.rect.h = h;
        }

        /** @brief Sets the X coordinate from the top left corner */
        void setX(int x){ data.rect.x = x; }
        /** @brief Sets the Y coordinate from the top left corner */
        void setY(int y){ data.rect.y = y; }
        /** @brief Sets the width of the rectangle */
        void setWidth(int w){ data.rect.w = w; }
        /** @brief Sets the height of the rectangle */
        void setHeight(int h){ data.rect.h = h; }

        /** @brief Increases the X coordinate by the specified value */
        void addX(int x){ data.rect.x += x; }
        /** @brief Increases the Y coordinate by the specified value */
        void addY(int y){ data.rect.y += y; }
        /** @brief Increases the width by the specified value */
        void addWidth(int w){ data.rect.w += w; }
        /** @brief Increases the height by the specified value */
        void addHeight(int h){ data.rect.h += h; }

        /** @brief Decreases the X coordinate by the specified value */
        void subX(int x){ data.rect.x -= x; }
        /** @brief Decreases the Y coordinate by the specified value */
        void subY(int y){ data.rect.y -= y; }
        /** @brief Decreases the width by the specified value */
        void subWidth(int w){ data.rect.w -= w; }
        /** @brief Decreases the height by the specified value */
        void subHeight(int h){ data.rect.h -= h; }

        /** @brief Returns the X coordinate of the top left corner */
        int getX(){ return data.rect.x; }
        /** @brief Returns the Y coordinate of the top left corner */
        int getY(){ return data.rect.y; }
        /** @brief Returns the width of the rectangle */
        int getWidth(){ return data.rect.w; }
        /** @brief Returns the height of the rectangle */
        int getHeight(){ return data.rect.h; }

        /**
         * @brief Returns the rectData structure with the rectangle's parameters
         * 
         * @return rectData A copy of the internal rectangle structure
         */
        rectData get() {
            return data;
        }

        /**
         * @brief Fills the rectangle area on the surface with the specified color
         * 
         * If color parameters are not set, current color is used.
         * Or if you want to keep a specific color, specify -1
         * 
         * @param surface Pointer to SDL_Surface for drawing
         * @param r Red color component (0-255)
         * @param g Green color component (0-255)
         * @param b Blue color component (0-255)
        */
        void fill(SDL_Surface *surface, Uint8 r = -1, Uint8 g = -1, Uint8 b = -1) {
            r = r == -1 ? data.color.r : r;
            b = b == -1 ? data.color.b : b;
            g = g == -1 ? data.color.g : g;

            data.color.r = r;
            data.color.g = g;
            data.color.b = b;

            SDL_FillSurfaceRect(surface, &data.rect, SDL_MapSurfaceRGB(surface, r, g, b));
        }

        /**
         * @brief Updates the rectangle area on the surface with the object's current color
         * 
         * @param surface Pointer to SDL_Surface for drawing
         */
        void update(SDL_Surface *surface) {
            SDL_FillSurfaceRect(surface, &data.rect, SDL_MapSurfaceRGB(surface, data.color.r, data.color.g, data.color.b));
        }

        /**
         * @brief Checks if the current rectangle intersects with another
         * 
         * @param otrect Reference to another rect object for intersection check
         * 
         * @return true If rectangles intersect
         * @return false If no intersection
         */
        bool onTouch(rect& otrect) {
            if (data.rect.x < otrect.data.rect.x + otrect.data.rect.w &&
                data.rect.x + data.rect.w > otrect.data.rect.x &&
                data.rect.y < otrect.data.rect.y + otrect.data.rect.h &&
                data.rect.y + data.rect.h > otrect.data.rect.y) {
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

            if (mouseX >= data.rect.x && mouseX <= data.rect.x + data.rect.w &&
                mouseY >= data.rect.y && mouseY <= data.rect.y + data.rect.h) {
                return true;
            }
            return false;
        }
        
        /**
         * @brief Overloads the output operator for convenient display of rectangle parameters
         * 
         * Outputs position, size, and color of the rectangle to the stream
         */
        friend ostream& operator<<(ostream& os, rect& r) {
            os << "Rect(x: " << r.data.rect.x << ", y: " << r.data.rect.y 
               << ", w: " << r.data.rect.w << ", h: " << r.data.rect.h 
               << ", r: " << static_cast<int>(r.data.color.r) 
               << ", g: " << static_cast<int>(r.data.color.g) 
               << ", b: " << static_cast<int>(r.data.color.b) 
               << ")";
            return os;
        }
};

#endif