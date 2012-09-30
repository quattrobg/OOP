#include <iostream>
using namespace std;


class Point{

    double x_;
    double y_;

public:   
    Point(){
        x_=0.0;
        y_=0.0;    
    }

    Point(double x,double y){
        x_=x;
        y_=y;
    }

    double get_x(){
        return x_;
    }

    double get_y(){
        return y_;
    }

    void set_x(double x){
        x_=x;
    }

    void set_y(double y){
        y_=y;
    }

	void sum(double a){
		x_+=a;
		y_+=a;
	}

	void sub(double a){
		x_-=a;
		y_-=a;
	}

	void mul(double a){
		x_*=a;
		y_*=a;
	}

	void div(double a){
		x_/=a;
		y_/=a;
	}
};

class Rectangle{
    Point bl_;
    Point br_;
    Point ur_;
    Point ul_;
    
public:
	Rectangle(Point p1, Point p2){
        int a;
        if(p1.get_x() > p2.get_x()){
            if(p1.get_y() > p2.get_y()) a = 1;		// p1 = ur; p2 = bl;
            else a = 2; 							// p1 = br; p2 = ul;
        }else{
            if(p1.get_y() > p2.get_y()) a = 3; 		// p1 = ul; p2 = br;
            else a = 4; 							// p1 = bl; p2 = ur;
        }
        switch(a){
            case 1 : br_.set_x(p1.get_x());			// bottom right X
                     br_.set_y(p2.get_y());			// bottom right Y
                     
                     bl_.set_x(p2.get_x());			// bottom left X
                     bl_.set_y(p2.get_y());			// bottom left Y
                     
                     ur_.set_x(p1.get_x());			// upper right X
                     ur_.set_y(p1.get_y());			// upper right Y
                     
                     ul_.set_x(p2.get_x());			// upper left X
                     ul_.set_y(p1.get_y());			// upper left Y
                break;
            case 2 : br_.set_x(p1.get_x());
					 br_.set_y(p1.get_y());
					 
					 bl_.set_x(p2.get_x());
					 bl_.set_y(p1.get_y());
					 
					 ur_.set_x(p1.get_x());
					 ur_.set_y(p2.get_y());
					 
					 ul_.set_x(p2.get_x());
					 ul_.set_y(p2.get_x());
                break;
            case 3 : br_.set_x(p2.get_x());
					 br_.set_y(p2.get_y());
					 
					 bl_.set_x(p1.get_x());
					 bl_.set_y(p2.get_y());
					 
					 ur_.set_x(p2.get_x());
					 ur_.set_y(p1.get_y());
					 
					 ul_.set_x(p1.get_x());
					 ul_.set_y(p1.get_x());
                break;
            case 4 : br_.set_x(p2.get_x());
					 br_.set_y(p1.get_y());
					 
					 bl_.set_x(p1.get_x());
					 bl_.set_y(p1.get_y());
					 
					 ur_.set_x(p2.get_x());
					 ur_.set_y(p2.get_y());
					 
					 ul_.set_x(p1.get_x());
					 ul_.set_y(p2.get_x());
                break;
        }
    }
    
    Rectangle(double x, double y, double w, double h){
		bl_.set_x(x);
		bl_.set_y(y);
		
		br_.set_x(x+w);
		br_.set_y(y);
		
		ur_.set_x(x+w);
		ur_.set_y(y+h);
		
		ul_.set_x(x);
		ul_.set_y(y+h);
	}

	void belong(Point p){
		double x = p.get_x(), y = p.get_y();
		if((x >= bl_.get_x()) && (x <= br_.get_x())){
			if((y >= bl_.get_y()) && (y <= ul_.get_y())){
				cout << "Does belong to this rectangle." << endl;
			}else{
				cout << "Does not belong to this rectangle." << endl;
			}
		}else{
			cout << "Does not belong to this rectangle." << endl;
		}
	}

	void intersect(Rectangle r){
		int a = 0, bl = 0, br = 0, ul = 0, ur = 0;
		Rectangle rnew(0, 0, 0, 0);
		if((r.bl_.get_x() >= bl_.get_x()) && (r.bl_.get_x() <= br_.get_x())){
			if((r.bl_.get_y() >= bl_.get_y()) && (r.bl_.get_x() <= ul_.get_y())){
				a+=1;
				bl=1;
			}
		};
		if((r.br_.get_x() >= bl_.get_x()) && (r.br_.get_x() <= br_.get_x())){
			if((r.br_.get_y() >= bl_.get_y()) && (r.br_.get_x() <= ul_.get_y())){
				a+=1;
				br=1;
			}
		};
		if((r.ul_.get_x() >= bl_.get_x()) && (r.ul_.get_x() <= br_.get_x())){
			if((r.ul_.get_y() >= bl_.get_y()) && (r.ul_.get_x() <= ul_.get_y())){
				a+=1;
				ul=1;
			}
		};
		if((r.ur_.get_x() >= bl_.get_x()) && (r.ur_.get_x() <= br_.get_x())){
			if((r.ur_.get_y() >= bl_.get_y()) && (r.ur_.get_x() <= ul_.get_y())){
				a+=1;
				ur=1;
			}
		};
		switch(a){
			case 0 : cout << "The rectangles don't intersect." << endl;
				break;
			case 1 : if(bl == 1){
						rnew.bl_.set_x(r.bl_.get_x());
						rnew.bl_.set_y(r.bl_.get_y());

						rnew.br_.set_x(ur_.get_x());
						rnew.br_.set_y(r.bl_.get_y());

						rnew.ur_.set_x(ur_.get_x());
						rnew.ur_.set_y(ur_.get_y());

						rnew.ul_.set_x(r.bl_.get_x());
						rnew.ul_.set_y(ur_.get_y());
					 };
					 if(br == 1){
						rnew.bl_.set_x(ul_.get_x());
						rnew.bl_.set_y(r.br_.get_y());

						rnew.br_.set_x(r.br_.get_x());
						rnew.br_.set_y(r.br_.get_y());

						rnew.ur_.set_x(r.br_.get_x());
						rnew.ur_.set_y(ul_.get_y());

						rnew.ul_.set_x(ul_.get_x());
						rnew.ul_.set_y(ul_.get_y());
					 };
					 if(ur == 1){
						rnew.bl_.set_x(bl_.get_x());
						rnew.bl_.set_y(bl_.get_y());

						rnew.br_.set_x(r.ur_.get_x());
						rnew.br_.set_y(bl_.get_y());

						rnew.ur_.set_x(r.ur_.get_x());
						rnew.ur_.set_y(r.ur_.get_y());

						rnew.ul_.set_x(bl_.get_x());
						rnew.ul_.set_y(r.ur_.get_y());
					 };
					 if(ul == 1){
						rnew.bl_.set_x(r.ul_.get_x());
						rnew.bl_.set_y(br_.get_y());

						rnew.br_.set_x(br_.get_x());
						rnew.br_.set_y(br_.get_y());

						rnew.ur_.set_x(br_.get_x());
						rnew.ur_.set_y(r.ul_.get_y());

						rnew.ul_.set_x(r.ul_.get_x());
						rnew.ul_.set_y(r.ul_.get_y());
					 };
				break;
			case 2 : if((bl == 1) && (br == 1)){
						rnew.bl_.set_x(r.bl_.get_x());
						rnew.bl_.set_y(r.bl_.get_y());

						rnew.br_.set_x(r.br_.get_x());
						rnew.br_.set_y(r.br_.get_y());

						rnew.ur_.set_x(r.br_.get_x());
						rnew.ur_.set_y(ul_.get_y());

						rnew.ul_.set_x(r.bl_.get_x());
						rnew.ul_.set_y(ul_.get_y());
					 };
					 if((bl == 1) && (ul == 1)){
						rnew.bl_.set_x(r.bl_.get_x());
						rnew.bl_.set_y(r.bl_.get_y());

						rnew.br_.set_x(br_.get_x());
						rnew.br_.set_y(r.bl_.get_y());

						rnew.ur_.set_x(br_.get_x());
						rnew.ur_.set_y(r.ul_.get_y());

						rnew.ul_.set_x(r.ul_.get_x());
						rnew.ul_.set_y(r.ul_.get_y());
					 };
					 if((br == 1) && (ur == 1)){
						rnew.bl_.set_x(bl_.get_x());
						rnew.bl_.set_y(r.br_.get_y());

						rnew.br_.set_x(r.br_.get_x());
						rnew.br_.set_y(r.br_.get_y());

						rnew.ur_.set_x(r.ur_.get_x());
						rnew.ur_.set_y(r.ur_.get_y());

						rnew.ul_.set_x(bl_.get_x());
						rnew.ul_.set_y(r.ur_.get_y());
					 };
					 if((ur == 1) && (ul == 1)){
						rnew.bl_.set_x(r.ul_.get_x());
						rnew.bl_.set_y(bl_.get_y());

						rnew.br_.set_x(r.ur_.get_x());
						rnew.br_.set_y(bl_.get_y());

						rnew.ur_.set_x(r.ur_.get_x());
						rnew.ur_.set_y(r.ur_.get_y());

						rnew.ul_.set_x(r.ul_.get_x());
						rnew.ul_.set_y(r.ul_.get_y());
					 };
				break;
			case 4 : cout << "The rectangles don't intersect." << endl;
				break;
		}
		rnew.dump();
	}
    
	void unite(Rectangle r){
		double ho, hr, hnew;
		double wo, wr, wnew;
		ho = ul_.get_y() - bl_.get_y();
		hr = r.ul_.get_y() - r.bl_.get_y();
		hnew = ho + hr;
		wo = br_.get_x() - bl_.get_x();
		wr = r.br_.get_x() - r.bl_.get_x();
		wnew = wo + wr;
		
		Rectangle rnew(bl_.get_x(), bl_.get_y(), wnew, hnew);
		rnew.dump();
	}

	void dump(){
		cout << "Rectangle : " << endl;
		cout << "A (bottom left) [" << bl_.get_x() << ";" << bl_.get_y() << "]" << endl;
		cout << "B (bottom right) [" << br_.get_x() << ";" << br_.get_y() << "]" << endl;
		cout << "C (upper right) [" << ur_.get_x() << ";" << ur_.get_y() << "]" << endl;
		cout << "D (upper left) [" << ul_.get_x() << ";" << ul_.get_y() << "]" << endl;
	}
	
};

int main(){

    return 0;
}
