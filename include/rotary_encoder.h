#ifndef ROTARY_ENCODER_H_MARK
#define ROTARY_ENCODER_H_MARK 1



class RotaryEncoder
{
    public:
        // void initialize(void);
        void run(void);
        int rotary_encoder_pos;
        int CLK = 5;     // PIN5
        int DAT = 4;     // PIN4
        int BUTTON = 3;  // PIN3
        RotaryEncoder();

    private:
        enum rotary_encoder_state{
            Idle,
            Turned,
            Pushed
         };
        rotary_encoder_state re_state;

        // const int interruptA = 0;      
        const int interruptA = 5;   
        const int interruptB = 1;      


        // enum direction_state{
        //     Backward,
        //     Forward
        // };
        // direction_state direction;


};

#endif