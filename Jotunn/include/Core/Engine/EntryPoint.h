#pragma once

#include "Application.h"

/**
 * Function defined in the client which creates the application
 */
extern Jotunn::Application* Jotunn::CreateApplication();

/**
 * The overall entry point for applications making use of the Jotunn engine
 * 
 * Creates and runs the Jotunn application
 */
int main(int argc, char** argv);