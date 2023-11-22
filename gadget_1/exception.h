#pragma once

class CIndexException : public std::exception {
public:
    CIndexException(const char* message) : std::exception(message) {}
};

class CInputException : public std::exception {
public:
    CInputException(const char* message) : std::exception(message) {}
};