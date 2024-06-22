USES
     math;
const
     finp='test.inp';
     fout='test.out';
     MAXN=100;

type hcn=record x1,y1,x2,y2: longint; end;

var
   h: array[1..MAXN] of hcn;
   f: array[1..MAXN] of longint;
   i,j,n,kq: longint;
   tam:hcn;

function dientich(a:hcn):longint;
begin
     with a do dientich:=(x2-x1)*(y2-y1);
end;

function bao(a,b:hcn):boolean;
begin
     bao:=(a.x1<=b.x1) and (b.x2<=a.x2) and (a.y1<=b.y1) and (b.y2<=a.y2);
end;

begin
     assign(input,finp);
     reset(input);
     assign(output,fout);
     rewrite(output);

     readln(n);
     for i:=1 to n do
         with h[i] do readln(x1,y1,x2,y2);
     for i:=1 to n-1 do
         for j:=i+1 to n do
             if (dientich(h[i])<dientich(h[j])) then tam:=h[i];h[i]:=h[j];h[j]:=tam;
     kq:=0;
     for i:=1 to n do
     begin
          f[i]:=1;
          for j:=i-1 downto 1 do
              if bao(h[j],h[i]) then f[i]:=max(f[i],f[j]+1);
          if (f[i]>kq) then kq:=f[i];
     end;
     writeln(kq);

     close(input);
     close(output);
end.
