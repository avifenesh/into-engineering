%ifdef DARWIN
  %define G(x) _ %+ x
%else
  %define G(x) x
%endif
