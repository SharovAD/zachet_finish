/*
 * Window.h
 *
 *  Created on: 14 ���. 2020 �.
 *      Author: unyuu
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include <memory>
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

class Window
{
public:
	// ������� ���� ��-���������
	static constexpr int DEFAULT_WIDTH = 1366;
	static constexpr int DEFAULT_HEIGHT = 768;
protected:
	// ��������� �� ���� SDL
	std::shared_ptr<SDL_Window> _window;
	// ��������� �� �������� OpenGL
	std::shared_ptr<void> _gl_context;

	// ������ � ������ ����
	int _width, _height;
public:
	// ����������� ������ Window
	Window(int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);
	// ���������� ������ Window
	virtual ~Window() = default;

	// ������ ��� ������ ����
	int width() const { return _width; }
	// ������ ��� ������ ����
	int height() const { return _height; }

	// 	�������� ����
	void main_loop();

	// ����� ��������� ��������� ����
	virtual void setup() { }

	// ����� ��������� ����
	virtual void render() { }

	// ����� ��������� �������
	virtual void handle_event(SDL_Event &event) { }

	// ����� ��������� ������
	virtual void handle_keys(const Uint8 * keys) { }

	// ����� ��������� ������
	virtual void handle_logic() { }
};


#endif /* WINDOW_H_ */
