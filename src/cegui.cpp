/*
 * =====================================================================================
 *
 *       Filename:  cegui.cpp
 *
 *    Description:  cegui first
 *
 *        Version:  1.0
 *        Created:  2012年10月24日 08时49分38秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  aowen 
 *   Organization:  
 *
 * =====================================================================================
 */
/*
 *  * Adapted by: Johnny Souza - johnnysouza.js@gmail.com
 *   * Date: 19/01/07 17:00
 *    * Description: Using CEGUI with SDL and OpenGL
 *     */

#include <stdio.h>
#include <stdlib.h>

#include <SDL/SDL.h>


#include <CEGUI.h>
#include <RendererModules/OpenGL/CEGUIOpenGLRenderer.h>

#include <GL/gl.h>
#include <GL/glu.h>

void handle_mouse_down(Uint8 button)
{
    switch ( button ) {
        case SDL_BUTTON_LEFT:
            CEGUI::System::getSingleton().injectMouseButtonDown(CEGUI::LeftButton);
            break;
        case SDL_BUTTON_MIDDLE:
            CEGUI::System::getSingleton().injectMouseButtonDown(CEGUI::MiddleButton);
            break;
        case SDL_BUTTON_RIGHT:
            CEGUI::System::getSingleton().injectMouseButtonDown(CEGUI::RightButton);
            break;

        case SDL_BUTTON_WHEELDOWN:
            CEGUI::System::getSingleton().injectMouseWheelChange( -1 );
            break;
        case SDL_BUTTON_WHEELUP:
            CEGUI::System::getSingleton().injectMouseWheelChange( +1 );
            break;
    }
}


void handle_mouse_up(Uint8 button)
{
    switch ( button )
    {
        case SDL_BUTTON_LEFT:
            CEGUI::System::getSingleton().injectMouseButtonUp(CEGUI::LeftButton);
            break;
        case SDL_BUTTON_MIDDLE:
            CEGUI::System::getSingleton().injectMouseButtonUp(CEGUI::MiddleButton);
            break;
        case SDL_BUTTON_RIGHT:
            CEGUI::System::getSingleton().injectMouseButtonUp(CEGUI::RightButton);
            break;
    }
}


void inject_input (bool & must_quit) 
{
    SDL_Event e;
    /*  go through all available events */
    while (SDL_PollEvent(&e)) {
        /*  we use a switch to determine the event type */
        switch (e.type) {
            /*  mouse motion handler */
            case SDL_MOUSEMOTION:
                /*  we inject the mouse position directly. */
                CEGUI::System::getSingleton().injectMousePosition(static_cast<float>(e.motion.x),static_cast<float>(e.motion.y));
                break;

                /*  mouse down handler */
            case SDL_MOUSEBUTTONDOWN:
                /*  let a special function handle the mouse button
                 *  down event */
                handle_mouse_down (e.button.button);
                break;

                /*  mouse up handler */
            case SDL_MOUSEBUTTONUP:
                /*  let a special function
                 *  handle the mouse button
                 *  up event */
                handle_mouse_up (e.button.button);
                break;

                /*  key down */
            case SDL_KEYDOWN:
                /*  to tell CEGUI that a key was pressed, we inject the scancode. */
                CEGUI::System::getSingleton().injectKeyDown(e.key.keysym.scancode);
                /*  as for the character it's a litte more complicated.
                 *                   *
                 *                   we'll
                 *                   use
                 *                   for
                 *                   translated
                 *                   unicode
                 *                   value.
                 *                                   *
                 *                                   this
                 *                                   is
                 *                                   described
                 *                                   in
                 *                                   more
                 *                                   detail
                 *                                   below.
                 *                                                   */
                if ((e.key.keysym.unicode & 0xFF80) == 0) {
                    CEGUI::System::getSingleton().injectChar(e.key.keysym.unicode & 0x7F);
                }
                break;

                /*  key up */
            case SDL_KEYUP:
                /*  like before we inject the scancode directly. */
                CEGUI::System::getSingleton().injectKeyUp(e.key.keysym.scancode);
                break;

                /*  WM quit event occured */
            case SDL_QUIT:
                must_quit = true;
                break;

            case SDL_VIDEORESIZE:
                CEGUI::System::getSingleton().notifyDisplaySizeChanged(CEGUI::Size(e.resize.w,e.resize.h));
                break;
        }
    }
}


void inject_time_pulse(double& last_time_pulse)
{
    /*  get current "run-time" in seconds */
    double t = 0.001*SDL_GetTicks();
    /*  inject the time that passed since the last call */
    CEGUI::System::getSingleton().injectTimePulse( float(t-last_time_pulse) );
    /*  store the new time as the last time */
    last_time_pulse = t;
}

void render_gui()
{
    /*  clear the colour buffer */
    glClear( GL_COLOR_BUFFER_BIT );
    /*  render the GUI :) */
    CEGUI::System::getSingleton().renderGUI();
    /*  Update the screen */
    SDL_GL_SwapBuffers();
}


void main_loop () 
{
    bool must_quit = false;
    /*  get "run-time" in seconds */
    double last_time_pulse = 0.001*static_cast<double>(SDL_GetTicks());
    while (!must_quit) {
        inject_input (must_quit);
        inject_time_pulse (last_time_pulse);
        render_gui ();
    }
}


int main (int argc, char **argv) 
{
    SDL_Surface * screen;
    atexit (SDL_Quit);
    SDL_Init (SDL_INIT_VIDEO);
    screen = SDL_SetVideoMode (600, 480, 0, SDL_OPENGL);
    if (screen == NULL) {
        /*  Se ainda nÃ£o der, desiste! */ 
        fprintf (stderr, "ImpossÃ­vel ajustar ao vÃ­deo: %s\n", SDL_GetError ());
        exit (1);
    }
    CEGUI::OpenGLRenderer::bootstrapSystem();
    SDL_ShowCursor (SDL_DISABLE);
    SDL_EnableUNICODE (1);
    SDL_EnableKeyRepeat (SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
    main_loop();
}

