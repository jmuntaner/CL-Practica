function main
  vars
    a 1
    b 1
    end 1
    pi 1
  endvars

   %1 = 12
   a = %1
   %2 = 5
   %3 = a * %2
   %5 = 1
   %6 = a + %5
   %8 = a * %6
   %10 = %3 + %8
   b = %10
   %12 = a <= b
   %13 = 0
   %14 = a == %13
   %15 = not %14
   %16 = %12 and %15
   end = %16
   %17 = 3.3
   %18 = 1
   %19 = %18 / a
   %22 = float %19
   %21 = %17 +. %22
   %23 = 2.0
   %24 = -. %23
   %26 = float a
   %25 = %24 /. %26
   %27 = %21 -. %25
   pi = %27
   %29 = a == b
   %30 = %29 or end
   writei %30
   writeln
   %32 = a * b
   writei %32
   writeln
   %35 = 2
   %37 = float %35
   %36 = %37 *. pi
   writef %36
   writeln
   return
endfunction


