/* 
 * File:   Matrices.h
 * Author: vidar
 *
 * Created on 03. Juni 2014, 12:01
 */

#ifndef MATRICES_H
#define	MATRICES_H

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct MATRICES {
	  glm::mat4 MVP;
	  glm::mat4 M;
	  glm::mat4 V;
	  glm::mat4 P;
}Matrices;

#ifdef	__cplusplus
}
#endif

#endif	/* MATRICES_H */

