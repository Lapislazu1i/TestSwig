#pragma once
#include <memory>
#include <vector>
#define NOR_API extern

namespace lego
{


    extern int g_version_number;

    template <class T>
    NOR_API bool greater(T a, T b)
    {
        bool res = a > b;
        return res;
    }

    NOR_API int add(int a, int b);
    NOR_API void get_12_by_ref(int& a);
    NOR_API void get_12_by_ptr(int* res);
    NOR_API void get_13_by_ptr(int* output);
    NOR_API void get_14_by_ref(int& output);
    NOR_API void get_12_by_sptr(std::shared_ptr<int> a);
    NOR_API void free_pointer(void *pointer);
    NOR_API std::shared_ptr<int> make_shared_ptr_int(int a);
    NOR_API int* make_row_ptr_int(int a);
    NOR_API void free_row_ptr_int(int* a);
    NOR_API void receive_int_ptr(std::shared_ptr<int> a);


    // NOR_API std::unique_ptr<int> make_unique_ptr_int(int a);
    // NOR_API void receive_int_uptr(std::unique_ptr<int> a);
    template <class T>
    class Pos2
    {
    public:
        Pos2() = default;
        Pos2(T x_, T y_) : x(x_), y(y_) {}
        T x;
        T y;
    };

    NOR_API void print_pos2f(Pos2<float> a);

    struct Pos3
    {
        double x;
        double y;
        double z;
        Pos3(double x_, double y_, double z_) : x(x_), y(y_), z(z_){}
        Pos3 operator+(const Pos3& other)
        {
            Pos3 pos3{0, 0, 0};
            pos3.x = this->x + other.x;
            pos3.y = this->y + other.y;
            pos3.z = this->z + other.z;
            return pos3;
        }
    };

    NOR_API std::vector<Pos2<double>> get_vector_pos2();
    NOR_API void print_vector_pos2(const std::vector<Pos2<double>>& pos2s);

    class Shape
    {
    public:
        Shape()
        {
            nshapes++;
        }
        virtual ~Shape()
        {
            nshapes--;
        }
        double x, y;
        void move(double dx, double dy);
        virtual double area() = 0;
        virtual double perimeter() = 0;
        static int nshapes;
    };

    class Circle : public Shape
    {
    public:
        double radius;

    public:
        Circle(double r) : radius(r) {}
        Circle(const Circle &circle) = delete;
        Circle &operator=(const Circle &) = delete;
        Circle(Circle &&other)
        {
            if (this == &other)
                return;

            this->radius = other.radius;
            other.radius = 0;
        }
        Circle &operator=(Circle &&other)
        {
            if (this == &other)
                return other;
            this->radius = other.radius;
            other.radius = 0;
            return *this;
        }

        static Circle *make_row();
        // static std::unique_ptr<Circle> make_unique();
        virtual double area();
        virtual double perimeter();
    };


    class Square : public Shape
    {
    private:
        double width;

    public:
        Square(double w) : width(w) {}
        Square(const Square &other)
        {
            this->width = other.width;
        }

        Square(Square &&other) = delete;
        Square &operator=(Square &&other) = delete;
        Square &operator=(const Square &other)
        {
            this->width = other.width;
            return *this;
        }

        virtual double area();
        virtual double perimeter();
    };

    int get_sharp_nshapes(Shape *shape);
}