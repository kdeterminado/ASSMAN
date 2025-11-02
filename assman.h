#ifndef ASSMAN_H
#define ASSMAN_H


typedef struct AssNode AssNode;
typedef struct AssMan  AssMan;

typedef void *(*AssLoaderFn)(const char *path,  void *data);
typedef void  (*AssReleaseFn)(void      *asset, void *data);


void *AssMan_load(   
	const char   *path, 
	AssLoaderFn   loader,   
	void         *load_data, 
	AssReleaseFn  releaser, 
	void         *release_data
);
void  AssMan_release(const char *path);
void  AssMan_clear(  void);


#endif /* ASSMAN_H */
