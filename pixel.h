#ifndef PIXEL_H
#define PIXEL_H



#include "rasterizer.h"



typedef struct
{
    /** \brief Depth test comparison function */
    int depth_test;

    /** \brief Non-zero to enable alpha blending, zero to disable */
    int alpha_blend;

    /** \brief Non-zero to enable a texture layer, zero to disable */
    int texture_enable[MAX_TEXTURES];

    /** \brief Pointer to textures for different texture layers */
    texture* textures[MAX_TEXTURES];
}
pixel_state;



/**
 * \brief Overwrite the current pixel processor state
 *
 * \param s A pointer to a state structure
 */
void pixel_set_state( const pixel_state* s );

/**
 * \brief Read the current pixel processor state
 *
 * \param s A pointer to a state structure to write the current state to
 */
void pixel_get_state( pixel_state* s );

/**
 * \brief Draw a pixel
 *
 * \param v    A pointer to a rasterizer vertex structure
 * \param ptr  A pointer to the destination color buffer
 * \param dptr A pointer to the destination depth buffer
 */
void pixel_draw( const rs_vertex* v, unsigned char* ptr, int* dptr );



#endif /* PIXEL_H */

