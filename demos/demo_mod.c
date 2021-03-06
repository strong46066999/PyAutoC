#include "Python.h"
#include "PyAutoC.h"

static float add_numbers(int first, float second) {
  return first + second;
}

static void hello_world(char* person) {
	printf("Hello %s!", person);
}

static PyObject* call(PyObject* unused, PyObject* args) {
	PyObject* func = PyTuple_GetItem(args, 0);
	PyObject* fargs = PyTuple_GetSlice(args, 1, PyTuple_Size(args));
	PyObject* ret = PyAutoFunction_CallByName(PyString_AsString(func), fargs);
	Py_DECREF(fargs);
	return ret;
}

static PyMethodDef method_table[] = {
	{"call", call, METH_VARARGS, ""},
	{NULL, NULL, 0, NULL},
};

/*
PyMODINIT_FUNC initpyautoc_demo(void) {
	PyAutoC_Initialize();
  Py_AtExit(PyAutoC_Finalize);
  
	PyAutoFunction_Register(add_numbers, float, 2, int, float);	
	PyAutoFunction_RegisterVoid(hello_world, 1, char*);	
	
  Py_InitModule("pyautoc_demo", method_table);
}
*/

int main(int argc, char** argv) { return 0; };