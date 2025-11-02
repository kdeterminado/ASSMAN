![](./res/ASSMAN.png)

Short for "Asset Manager"

A simple standalone asset manager for games and such. Just copy `assman.h` and `assman.c` into your project and add it to your makefile or whatever it is you're using.



# API:

- `void *AssMan_load(   
      const char   *path, 
      AssLoaderFn   loader,   
      void         *load_data, 
      AssReleaseFn  releaser, 
      void         *release_data
  )`: Loads a file from disc if it's not allocated already, otherwise, just returns the currently allocated resource.
  

- `void  AssMan_release(const char *path)`: Releases a resource if it's no longer in use anywhere else, otherwise, it decrements the refcount.
  

- `void  AssMan_clear(  void)`: Clears the entire manager of all assets.

# License:

Zero BSD/Public Domain
