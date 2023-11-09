#include "lib.h"
#include <stdio.h>
#include <iostream>
#define M_PI 3.14159265358979323846
int lego::g_version_number = 100;



namespace lego
{

    NOR_API void get_12_by_ref(int& a)
    {
        a = 12;
    }
    NOR_API void get_12_by_ptr(int* res)
    {
        *res = 12;
    }
    NOR_API void get_13_by_ptr(int* output)
    {
        *output = 13;
    }
    NOR_API void get_14_by_ref(int& output)
    {
        output = 14;
    }

    NOR_API void get_12_by_sptr(std::shared_ptr<int> a)
    {
        *a = 12;
    }

    NOR_API void free_pointer(void* pointer)
    {
        if(pointer != nullptr)
        {
            delete pointer;
            pointer = nullptr;
        }


    }
    NOR_API int add(int a, int b)
    {
        return a + b;
    }
    NOR_API std::shared_ptr<int> make_shared_ptr_int(int a)
    {
        return std::make_shared<int>(a);
    }

    NOR_API int* make_row_ptr_int(int a)
    {
        return new int(a);
    }

    NOR_API void free_row_ptr_int(int* a)
    {
        delete a;
        a = nullptr;
    }


    NOR_API void receive_int_ptr(std::shared_ptr<int> a)
    {
        printf("shared ptr:%d\n", *a);
    }


    NOR_API void print_pos2f(Pos2<float> a)
    {
        printf("Pos2 x: %02f, y: %02f\n", a.x, a.y);
    }



    // NOR_API std::unique_ptr<int> make_unique_ptr_int(int a)
    // {
    //     return std::make_unique<int>(a);

    // }
    // NOR_API void receive_int_uptr(std::unique_ptr<int> a)
    // {
    //     printf("unique ptr:%d\n", *a);
    // }

    NOR_API std::vector<Pos2<double>> get_vector_pos2()
    {
        std::vector<Pos2<double>> res;
        Pos2<double> tmp(2.0, 3.0);
        res.emplace_back(tmp);
        res.emplace_back(tmp);
        res.emplace_back(tmp);
        return res;
    }

    NOR_API void print_vector_pos2(const std::vector<Pos2<double>>& pos2s)
    {
        for(const auto& pos : pos2s)
        {
            std::cout << pos.x << " " << pos.y <<"\n";
        }
    }




    /* Move the shape to a new location */
    void Shape::move(double dx, double dy)
    {
        x += dx;
        y += dy;
    }

    int Shape::nshapes = 0;

    Circle* Circle::make_row()
    {
        return new Circle(1);
    }

    double Circle::area()
    {
        return M_PI * radius * radius;
    }

    double Circle::perimeter()
    {
        return 2 * M_PI * radius;
    }

    double Square::area()
    {
        return width * width;
    }

    double Square::perimeter()
    {
        return 4 * width;
    }
    int get_sharp_nshapes(Shape* shape)
    {
        return shape->nshapes;
    }

}
