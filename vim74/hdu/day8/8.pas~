var
	i,j,k,l,m,n,t:longint;
	a,b:array[0..500000] of int64;
function max(x,y:longint):longint;inline;
begin
	if x>y then max:=x else max:=y;
end;
function min(x,y:longint):longint;inline;
begin
	if x<y then min:=x else min:=y;
end;
procedure built(z,x,y:longint);inline;
begin
	if x=y then
	begin
		read(a[z]);
		if a[z]<=1 then b[z]:=1 else b[z]:=0;
	end
	else
	begin
		built(z*2,x,(x+y) div 2);
		built(z*2+1,(x+y) div 2+1,y);
		a[z]:=a[z*2]+a[z*2+1];
		if (b[z*2]=1) and (b[z*2+1]=1) then b[z]:=1 else b[z]:=0;
	end;
end;
function op(z,x,y,l,r:longint):int64;inline;
var a2,a3,a4:int64;
begin
	if l>r then exit(0);
	if b[z]=1 then exit(0);
	if (x=l) and (y=r) and (l=r) then
	begin
		a2:=a[z];
		a[z]:=trunc(sqrt(a[z]));
		if a[z]<=1 then b[z]:=1;
		exit(a[z]-a2);
	end;
	a2:=op(z*2,x,(x+y) div 2,l,min((x+y) div 2,r));
	a3:=op(z*2+1,(x+y) div 2+1,y,max((x+y) div 2+1,l),r);
	a[z]:=a[z]+a2+a3;
	if (b[z*2]=1) and (b[z*2+1]=1) then b[z]:=1;
	exit(a2+a3);
end;
function cal(z,x,y,l,r:longint):int64;inline;
begin
	if l>r then exit(0);
	if (x=l) and (y=r) then exit(a[z]);
	exit(cal(z*2,x,(x+y) div 2,l,min(r,(x+y) div 2))+cal(z*2+1,(x+y) div 2+1,y,max((x+y) div 2+1,l),r));
end;
procedure swap(var x,y:longint);inline;
var z:longint;
begin
	z:=x;x:=y;y:=z;
end;

begin
	readln(n);
	built(1,1,n);
	readln;
	readln(m);
	for i:=1 to m do
	begin
		readln(j,k,l);
		if k>l then swap(k,l);
		case j of
		1:writeln(cal(1,1,n,k,l));
		0:op(1,1,n,k,l);
	end;
end;
end.
