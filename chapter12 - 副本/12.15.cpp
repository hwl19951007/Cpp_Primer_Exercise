void f(destination &d /* �������� */){
    connection c = connect(&d);
    shared_ptr<connection> p(&c, [] (connection *p){ disconnection(*p); } ) ;
}