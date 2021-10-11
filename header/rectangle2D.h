#ifndef RECTANGLE2D
#define RECTANGLE2D
struct vec2{
        float x;
        float y;
				// default + parameterized constructor
				vec2(int x=0, int y=0) : x(x), y(y)
				{
				}
				// assignment operator modifies object, therefore non-const
		    vec2& operator=(const vec2& a)
		    {
		        x=a.x;
		        y=a.y;
		        return *this;
		    }

		    // addop. doesn't modify object. therefore const.
		    vec2 operator+(const vec2& a) const
		    {
		        return vec2(a.x+x, a.y+y);
		    }

				vec2 operator-(const vec2& a) const
		    {
		        return vec2(a.x-x, a.y-y);
		    }

		    // equality comparison. doesn't modify object. therefore const.
		    vec2 operator==(const vec2& a) const
		    {
		        return (x == a.x && y == a.y);
		    }
};
class Rectangle2D{
	private:
		vec2 pos;
		vec2 size;
		int index;
	public:
		Rectangle2D(vec2 pos, vec2 size, int index);
		Rectangle2D();
		// Copy constructor
	  Rectangle2D(const Rectangle2D &rect);
		~Rectangle2D();
		void setPos(vec2 pos);
		vec2 getPos();
		float getLeftBound();
		float getTopBound();
		vec2 getSize();
		int getIndex();

};
bool isIntersect(Rectangle2D rectA, Rectangle2D rectB);
#endif
