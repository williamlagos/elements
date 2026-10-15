#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "elements.h"
#include "matrix.h"
#include "ranking.h"
#include "tree.h"

namespace py = pybind11;

PYBIND11_MODULE(_elements, m) {
    m.doc() = "Elements Core C++ engine primitives bindings for Python";

    // Bind Element
    py::class_<Element>(m, "Element")
        .def(py::init<std::string>(), py::arg("name") = "")
        .def_property_readonly("name", &Element::getName)
        .def_property_readonly("hit_points", &Element::getHitPoints)
        .def_property_readonly("width", &Element::getWidth)
        .def_property_readonly("height", &Element::getHeight)
        .def_property_readonly("speed_x", &Element::getSpeedX)
        .def_property_readonly("speed_y", &Element::getSpeedY)
        .def_property_readonly("pos_x", &Element::getPositionX)
        .def_property_readonly("pos_y", &Element::getPositionY)
        .def("hurt", &Element::hurtElement, py::arg("points"))
        .def("heal", &Element::healElement, py::arg("points"))
        .def("set_size", &Element::whichSize, py::arg("width"), py::arg("height"))
        .def("set_speed", &Element::whichSpeed, py::arg("x_axis"), py::arg("y_axis"))
        .def("set_position", &Element::whichPosition, py::arg("x"), py::arg("y"))
        .def("__repr__", [](const Element &e) {
            return "<Element name='" + e.getName() + "' hp=" + std::to_string(e.getHitPoints()) +
                   " pos=(" + std::to_string(e.getPositionX()) + "," + std::to_string(e.getPositionY()) + ")>";
        });

    // Bind Elements container
    py::class_<Elements>(m, "Elements")
        .def(py::init<>())
        .def(py::init<bool>(), py::arg("status"))
        .def("add_element", &Elements::addElement, py::arg("name"))
        .def("rem_element", &Elements::remElement)
        .def("count", &Elements::getElementCount)
        .def("__len__", &Elements::getElementCount)
        .def("__getitem__", [](Elements &self, int index) -> Element* {
            if (index < 0 || index >= self.getElementCount()) {
                throw py::index_error("Element index out of range");
            }
            return self.getElement(index);
        }, py::return_value_policy::reference_internal);

    // Bind IntMatrix
    py::class_<IntMatrix>(m, "IntMatrix")
        .def(py::init<int>(), py::arg("size") = 0)
        .def(py::init<int, int, int>(), py::arg("cols"), py::arg("rows"), py::arg("initial_value") = 0)
        .def_property_readonly("cols", &IntMatrix::getCols)
        .def_property_readonly("rows", &IntMatrix::getRows)
        .def("get", &IntMatrix::get, py::arg("col"), py::arg("row"))
        .def("set", &IntMatrix::set, py::arg("col"), py::arg("row"), py::arg("val"))
        .def("create_row", &IntMatrix::createRow)
        .def("create_col", &IntMatrix::createCol)
        .def("clean", &IntMatrix::clean)
        .def("__getitem__", [](const IntMatrix &self, std::pair<int, int> pos) {
            return self.get(pos.first, pos.second);
        })
        .def("__setitem__", [](IntMatrix &self, std::pair<int, int> pos, int val) {
            self.set(pos.first, pos.second, val);
        })
        .def("__repr__", [](const IntMatrix &self) {
            return "<IntMatrix cols=" + std::to_string(self.getCols()) + " rows=" + std::to_string(self.getRows()) + ">";
        });

    // Bind FloatMatrix
    py::class_<FloatMatrix>(m, "FloatMatrix")
        .def(py::init<int>(), py::arg("size") = 0)
        .def(py::init<int, int, float>(), py::arg("cols"), py::arg("rows"), py::arg("initial_value") = 0.0f)
        .def_property_readonly("cols", &FloatMatrix::getCols)
        .def_property_readonly("rows", &FloatMatrix::getRows)
        .def("get", &FloatMatrix::get, py::arg("col"), py::arg("row"))
        .def("set", &FloatMatrix::set, py::arg("col"), py::arg("row"), py::arg("val"))
        .def("clean", &FloatMatrix::clean);

    // Bind Codes (Quadtree)
    py::class_<Codes>(m, "Codes")
        .def(py::init<>())
        .def("black", &Codes::black)
        .def("white", &Codes::white)
        .def("gray", &Codes::gray)
        .def("parse_code", &Codes::parseCode, py::arg("code"))
        .def("clear_tree", &Codes::clearTree)
        .def("print_tree", &Codes::printTree)
        .def("source_tree", &Codes::sourceTree)
        .def("blacks", &Codes::blacks)
        .def("__repr__", [](Codes &self) {
            return "<Codes tree='" + self.printTree() + "' blacks=" + std::to_string(self.blacks()) + ">";
        });

    // Bind Content & Tree
    py::class_<Content>(m, "Content")
        .def(py::init<std::string>(), py::arg("name") = "")
        .def_property("name", &Content::getName, &Content::setName);

    py::class_<Tree>(m, "Tree")
        .def(py::init<>())
        .def("is_empty", &Tree::isEmpty)
        .def("insert", &Tree::insert, py::arg("content"))
        .def("remove", &Tree::remove, py::arg("name"));
}
