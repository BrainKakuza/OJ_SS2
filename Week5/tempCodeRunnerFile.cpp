Point p1;
    p1.x = 20;
    p1.y = 15;
    Point p2;
    p2.x = 10;
    p2.y = 5;
    Point p3;
    p3.x = 10;
    p3.y = 5;
    Point p4;
    p4.x = 30;
    p4.y = 5;
    Point p5;
    p5.x = 30;
    p5.y = 5;
    Point p6;
    p6.x = 20;
    p6.y = 15;

    Segment s1(p1,p2);
    Segment s2(p3,p4);
    Segment s3(p5,p6);

    Triangle t1(s1,s2,s3);

    t1.isTriangle(s1,s2,s3);
    t1.getArea();