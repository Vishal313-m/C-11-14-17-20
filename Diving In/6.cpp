// C++ PROGRAM EXECUTION MODEL & MEMORY MODEl

/*In this lecture, we're going to explore the C plus plus execution model and show you a simplified version of the memory model of your C++ program.

Here is how our program looks.

It is a simple program in our main function.
It is going to call a simple function that is going to add two numbers.

We have seen a program like this before, and when we compile it, it's going to be turned into a binary.

This black icon here represents the binary executable, and it is not in the format that you can read
with your eyes.
If we come back here to what we were doing in the last lecture, we can see our rooster executable binary
here.
If we try to open it here, you're going to see that Visual Studio code is going to say the file is
not displayed in the editor because it is either binary or uses an unsupported text encoding.
So it says, I can't really say this because it's binary and it says, Do you want to open it anyway?
If I try to open it, it's going to be just some gibberish because this is binary.
It is meant to be read by programs.
It is not meant to be by ides or text editors like Visual Studio Code.
So this is the binary file we have here.

I tried to put a simplified version of this program to represent binary so that we can follow it up,

but it is not in a form that is readable by any human out there unless you are a machine.

So why is it in binary?

Because the binary format is easily understandable by your CPU and we're going to see how your program
is loaded in memory and executed statement by statement by the CPU so that you can really understandthis.

So here is a representation of your program.

Here we have our hard drive and we have the program sitting somewhere on our hard drive in binary format
and it's waiting to be run by you by double clicking on it or opening it in the terminal.
And on the left here we see a representation of the memory of our computer.
And when I say memory, I mean random access memory.

I don't mean memory on your hard drive.

This should be really clear.

This is the random access memory of your computer that is running your programs very fast.
So when you double click on our program or if we open it in the terminal, the binary file is going
to be loaded up in memory.

And you see it in red here.

This is a representation of that and it is ready to be run by the CPU.
By the time the CPU sees in the memory location, it's going to know I have a program to run and the
CPU is going to start running it statement by statement and it's going to start by the top.
So it's going to see that it needs to allocate space to store our integer A It's going to allocate to
that.

Somewhere on the memory in yellow here you see A and it's going to see that it should store in a value
of ten and it's going to do that. You can see that here.

It's going to go to the next statement and the next statement tells it to allocate space for a value
B, and it's going to store in a five.
It's going to go to the next statement.
It's a variable called C, It's going to allocate space for it.
But we didn't specify a value for C, So what it's going to do is storing some junk value.
The value in there is really unspecified at the moment.
It's going to jump to the next statement and what it's going to do is print some things on the console
and it is going to do that.

It's going to jump to the next statement and it is going to print statement two.
And here it is going to notice that it is going to call a function.
I don't know if you have noticed, but the CPU has allocated a special memory location for our function.
The function doesn't leave with our code here or anywhere near the variables that we have here.
They might be a huge chunk of memory between these 2 or 3 things.
So the CPU knows that it is going to jump to another location.
It's going to ask itself if I jump to that location to run this function, how am I going to come back?
And the CPU is smart enough to store the return address and that's what it's going to do.
It's going to say, if I go to that function, I want to come back to the address six and run whatever
is after this address.

So it's going to store six and CPU memory and it's going to jump to the function.
It's going to take the first parameter as a and the second parameter as B, So A is then the parameter
one is going to be ten, It's going to take parameter two, it's going to be five because it is B here
and in B we have a five and it is going to jump to the next statement in the function and it is going
to add up parameter one and parameter two after it adds those things up, it's going to return the result
to C, We can see that here.

Okay.

That's what the CPU is going to do.
It's going to put the result in C and the result is a 15.
So we're going to write that in there.
And now that the function is really done, it's going to come back to it's address and it is going to
jump to the next segment.

After that, it is going to print three, statement three, it is going to jump to the next line and
print statement for it's going to do that.
And by this time, we have reached the end of our program and it is going to be popped off the memory.
And your program is basically going to end.

This is how your program is executed by your CPU.
And why am I showing you this?
Because it is really good to have an idea of how memory is allocated and used by your program.
Another good reason is that some C plus plus feature require you to have an understanding of a memory
model like this to understand how they work.
For example, you have seen that to call this function, the program had to jump from address 6 to 30.
And this is really heavy, especially if you are running a simple function like we are doing here to
add two numbers so the CPU can realize that and optimize this call to the function to an inline function
and add these two numbers up right here at address six without jumping to this address here and this
may come in handy and you need an understanding of this memory model to really understand these features.
This is just one example I am giving you.

You are going to reuse this model a lot in your career as a C plus plus developer, and I thought it
was a really good idea for you to understand it firsthand.
This is really all I had to share in this lecture.
,*/