#pragma once
#include <iostream>

class Student
{
public:
	Student() = default;
	Student(int age, std::string name) : m_age(age), m_name(name) {}
	Student(const Student& other)
	{
		m_age = other.m_age;
		m_name = other.m_name;

	}
	Student& operator=(Student&& movedStudent)
	{
		m_age = movedStudent.m_age;
		m_name = movedStudent.m_name;
	}
	int m_age{};
	std::string m_name{};
	friend std::ostream& operator<< (std::ostream& out, const Student& c) {
		out << "\nName: " << c.m_name << "\tAge: " << c.m_age;
		return out;
	}
};