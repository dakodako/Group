# Group

#最后版本邮件


Dear Jonathan

Hello again. I'm Shiyu, your student from DSD last semester. How have you been?

So we are current working on the project of a panoramic video camera
and wishing to take advantage of the high IO data rate as well as the
parallel processing ability of FPGA. You have probably speak to
another team of this project as well.

Would it be possible for you to take a bit of your precious time to
give us some directions on the problem that we have encountered have
so far, by having a short meeting with our team?

If you really can't because you are too busy, would it be possible for
you to answer our following questions through email?

1: About Interfacing
How should we collect data from cameras and input it to the FPGA? We
researched about HSMC Quad Video Daughter Card but the cost of the
board and the difficulty of development is a bit too much for us. So
we are currently looking at a FPGA board that is specified for video
signal processing and it has 4 way S-video input. It's using the
architecture of Cyclone 4 + an ARM processor which is very similar to
the DE1 SoC board that we used in DSD. However, we are not too sure
about how does the board decode these video signals to something that
the FPGA could understand(convert to RBG pixel matrices maybe?)

2.About HPS-FPGA bridge
Is it possible for us to decode signal from USB cameras using the HPS
the transfer the data to FPGA using the HPS-FPGA bridge? This idea
sounds pretty reasonable because there's usually usb host controller
attached to HPS on soc boards. However, we haven't actually seen
anyone has successfully done it yet.

3. About analog signal and digital signal conversion
Since the boards we looked up for are all using s-video input and we
learnt that it is an analogue transmission method, how can we convert
the input signal which is supposed to be digital to analog to put it
into the board and then decode it back to digital so that we can use
image processing algorithms on it?

It will be great if we can have a short meeting with you.If you are
able to have a meeting with us please just discuss these questions on
the meeting.

Your help will be highly appreciated.
Thanks in advance
