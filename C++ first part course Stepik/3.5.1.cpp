char & get_c(Cls &cls){
     return *(char *)(&cls);
}


double & get_d(Cls &cls){
     return *(double *)((char*)&cls + 8);
}

int & get_i(Cls &cls) {
     return *(int *)((char *)&cls + 16);
}