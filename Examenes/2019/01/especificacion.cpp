predicate terrenoLLano (s : seq<int>) 
{ forall k :: 0 < k < |s| ==> s[..][k-1] == s[k] || s[..][k-1] + 1 == s[k] || s[..][k-1] - 1 == s[k]}

/*
function countLLanos (s : seq<int>, x : nat) : nat
requires 1 < x < |s|
{
	if (|s| < 2) then 0
	else if (terrenoLLano(s[..x])) then 1 + countLLanos(s[longSegmento(s)..],x)
	else countLLanos(s[longSegmento(s)..],x)
}
*/

method ejercicio1 (v : array<int>, lPista : int) returns (cuantas : int, w : array<int>) 
requires v != null  && v.Length >= 0 && 1 < lPista <= v.Length
ensures w != null && w.Length == v.Length
ensures 0 <= cuantas <= v.Length
ensures forall k :: 0 <= k < cuantas ==> 0 <= w[k] <= v.Length - lPista
//ensures cuantas == countLLanos(v[..],lPista)
ensures forall k :: 0 <= k < cuantas ==> terrenoLLano(v[w[k]..w[k]+lPista])
{
	w := new int[v.Length];
    var iniAct := 0; var i := 1; cuantas := 0; 
    while (i < v.Length) 
	invariant 1 <= i <= v.Length && 0 <= iniAct < i
	invariant 0 <= cuantas <= i
	invariant forall k :: 0 <= k < cuantas ==> 0 <= w[k] <= v.Length - lPista
	invariant terrenoLLano(v[iniAct..i])
	invariant forall k :: 0 <= k < cuantas ==> terrenoLLano(v[w[k]..w[k]+lPista])
	{
        if ((v[i-1] == v[i] || v[i-1] + 1 == v[i] || v[i-1] - 1 == v[i])) { // terreno llano
            if (i-iniAct + 1 == lPista) { 
				w[cuantas] := iniAct;
				cuantas := cuantas + 1;
			}
			else {
			}
       }
        else { 
			iniAct := i;
		}
		i := i + 1;
    }
}