void f(destination &d /* 其他参数 */){
    connection c = connect(&d);
    shared_ptr<connection> p(&c, [] (connection *p){ disconnection(*p); } ) ;
}